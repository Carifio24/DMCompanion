#include "keys.h"
#include "monster_parse.h"
#include "string_helpers.h"
#include "speed_type.h"
#include "json_helpers.h"
#include "damage_info.h"

#include <iostream>
#include <boost/algorithm/string/predicate.hpp>

namespace DnD {

DamageInfo identify_damage_info(const std::string& s, const std::map<DamageType,std::string>& damageTypes) {

    // Make the string all lowercase
    std::string s_lower = lowercase(s);

    // Get the damage type
    for (const auto& elt : damageTypes) {
        if (boost::contains(s_lower, elt.second)) {
            dInf.damage_type = elt.first;
            break;
        }
    }

    // Whether the damage type is magical, nonmagical, or neither
    std::string mag = "magical";
    std::string nonmag = "nonmagical";
    if (boost::contains(s_lower, nonmag)) {
        dInf.magic_type = MagicType::Nonmagical;
    } else if (boost::contains(s_lower, mag)) {
        dInf._mag_type = MagicType::Magical;
    } else {
        dInf._mag_type = MagicType::Any;
    }

    // Return
    return dInf;

}


std::vector<DamageInfo> damage_modifiers_from_string(std::string s, const std::string& sep) {

    std::vector<DamageInfo> dmods;

    // Only need to do anything if the string isn't empty
    if (!s.empty()) {
        boost::replace_all(s, "and ", "");
        std::vector<std::string> split_data = jstring::split(s, sep);
        dmods.reserve(split_data.size());

        std::cout << "s is: " << s << std::endl;
        std::cout << "split_data.size() is " << split_data.size() << std::endl;
        std::cout << "dmods.size() is " << dmods.size() << std::endl;

        for (size_t i = 0; i < split_data.size(); i++) {
            dmods.push_back(identify_damage_info(split_data[i]));
        }
    }
    return dmods;

}

Monster parse_monster(const Json::Value& root, MonsterBuilder& b) {

    using namespace keys;

    // Get the basic info
    b.set_name(root[name_k].asString());
    b.set_size(Size::from_name(root[size_k].asString()));
    
    b.set_type(root[type_k].asString());
    b.set_subtype(root[subtype_k].asString());
    b.set_alignment(root[alignment_k].asString());
    b.set_armor_class(root[armor_class_k].asInt());
    b.set_hit_points(root[hit_points_k].asInt());
    m.hitDice = dice_from_string(root[hit_dice_k].asString());
    b.set_challenge_rating(Fraction::from_string(root[challenge_rating_k].asString()));

    // Get the various speeds
    std::vector<std::string> speed_strs = split(root[speed_k].asString(), ", ");
    std::vector<Speed> speeds;
    speeds.reserve(speed_strs.size());
    for (const std::string& s : speed_strs) {
        std::cout << "Speed string: " << s << std::endl;
        std::vector<std::string> split_data = split(s, " ");
        std::cout << "Split speed string size: " << split_data.size() << std::endl;
        if (split_data.size() == 2) { // Walking speed
            Distance dist = Distance::from_string(s);
            speeds.push_back(std::make_pair(SpeedTypes::Walking, speed_value));
        } else { // Other speed type
            split_data = split(s, " ", 2);
            Distance dist = Distance::from_string(split_data[1]);
            const SpeedType& speed_type = SpeedType::from_name(split_data[0]);
            speeds.push_back(std::make_pair(speed_type, dist));
        }
    }
    b.set_speeds(speeds);

    // Get any speeds in alternate forms
    std::vector<std::string> alt_speeds;
    if (root.isMember(alt_speeds_k)) {
        
        Json::Value alt_speeds_json = root[alt_speeds_k];
        alt_speeds.reserve(alt_speeds_json.size());

        for (const Json::Value& alt_speed : alt_speeds_json) {
            std::string condition = alt_speed[condition_k].asString();
            std::vector<std::string> alt_speed_strs = split(alt_speed[speed_k].asString(), ", ");

            for (const std::string& s : alt_speed_strs) {
                std::vector<std::string> split_data = split(s, " ");
                Distance dist;
                Speed speed;
                if (split_data.size() == 2) { // Walking speed
                    dist = Distance::from_string(s);
                    speed = Speed(SpeedTypes::Walking, dist);
                } else { // Other speed type
                    split_data = split(s, " ", 2);
                    const SpeedType& speed_type = SpeedType::from_name(split_data[0]);
                    dist = Distance::from_string(split_data[1]);
                    speed = Speed(SpeedTypes::Walking, dist);
                }
                std::pair<Speed,std::string> speed_info{speed, condition};
                alt_speeds.push_back(speed_info);
            }
        }
    }
    b.set_alternate_speeds(alt_speeds);

    // Ability scores
    b.set_strength(root[str_k].asInt());
    b.set_dexterity(root[dex_k].asInt());
    b.set_constitution(root[con_k].asInt());
    b.set_intelligence(root[int_k].asInt());
    b.set_wisdom(root[wis_k].asInt());
    b.set_charisma(root[chr_k].asInt());

    // Saving throw modifiers
    b.set_strength_save(int_if_member(root, str_sv_k));
    b.set_dexterity_save(int_if_member(root, dex_sv_k));
    b.set_constitution(int_if_member(root, con_sv_k));
    b.set_intelligence_save(int_if_member(root, int_sv_k));
    b.set_wisdom_save(int_if_member(root, wis_sv_k))
    b.set_charisma_save(int_if_member(root, chr_sv_l));

    // Other statistics
    b.set_history(int_if_member(root, history_k));
    b.set_perception(int_if_member(root, perception_k));

    // Vulnerabilities, resistances, immunities
    const std::string list_sep = ", ";
    std::cout << "About to parse damage conditions" << std::endl;
    std::cout << string_if_member(root, dmg_vuls_k) << std::endl;
    b.set_damage_vulnerabilities(damage_modifiers_from_string(string_if_member(root, dmg_vuls_k), list_sep));
    b.set_damage_resistances(damage_modifiers_from_string(string_if_member(root, dmg_rsts_k), list_sep));
    b.set_damage_immunities(damage_modifiers_from_string(string_if_member(root, dmg_imns_k), list_sep));
    std::cout << "About to parse condition immunities" << std::endl;
    std::string data;
    std::vector<Condition* const> cond_imns;
    if ( !(data = root[cond_imns_k].asString()).empty() ) {
        std::vector<std::string> cond_strs = split(data, list_sep);
        conds.reserve(cond_strs.size());
        for (const std::string& s : cond_strs) {
            cond_imns.push_back(Condition::from_name(s));
        }
    }
    b.set_condition_immunities(cond_imns);

    // Senses and passive perception
    std::vector<std::string> senses_and_perception = split(root[senses_k].asString(), ", ");
    for (const std::string& s : senses_and_perception) {

        // If it's the passive perception
        std::vector<std::string> split_data = split(s, " ");
        if (boost::starts_with(s, "passive Perception")) {
            m.passivePerception = std::stoi(split_data[2]);
        // Otherwise
        } else {
            int sense_range = std::stoi(split_data[1]);
            Sense sense_type = enum_from_name<Sense>(senseNames, split_data[0]);
            m.senses.push_back(std::make_pair(sense_type, sense_range));
        }
    }

    // Languages (just a string for now, need to work on this)
    m.languages = root[languages_k].asString();

    // Special abilities
    if (root.isMember(spcl_abls_k)) {
        m.specialAbilities = json_array_to_vector<Ability>(root[spcl_abls_k]);
    }

    // Actions and legendary actions
    if (root.isMember(actions_k)) {
        m.actions = json_array_to_vector<Action>(root[actions_k]);
    }
    if (root.isMember(leg_actions_k)) {
        m.legendaryActions = json_array_to_vector<Action>(root[leg_actions_k]);
    }

    return m;

}

} // end namespace DnD