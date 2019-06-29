#include <DnD/keys.h>
#include <DnD/string_helpers.h>
#include <DnD/speed_type.h>
#include <DnD/damage_info.h>
#include <DnD/enummaps.h>
#include <DnD/dice_set.h>
#include <DnD/special_ability.h>
#include <DnD/damage_type.h>

#include <QFile>
#include <QVector>
#include <QTextStream>
#include <iostream>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/replace.hpp>

#include <DnD/enummaps.h>

#include "monster_parse.h"
#include "json_helpers.h"

using namespace DnD;

DamageInfo identify_damage_info(std::string s) {

    // Make the string all lowercase
    std::string s_lower = lowercase(s);

    // Get the damage type
    const DamageType* dmg_type = &DamageTypes::Damage;
    for (auto x : DamageTypes::instances) {
        if (*x == DamageTypes::Damage) { continue; }
        std::string t(x->name());
        to_lowercase(t);
        if (boost::contains(s_lower, t)) {
            dmg_type = x;
            break;
        }
    }

    // Whether the damage type is magical, nonmagical, or neither
    const MagicType* mag_type = &MagicTypes::Any;
    for (auto x : MagicTypes::instances) {
        if (*x == MagicTypes::Any) { continue; }
        std::string t(x->name());
        to_lowercase(t);
        if (boost::contains(s_lower, t)) {
            mag_type = x;
            break;
        }
    }

    // Create and return
    DamageInfo d_info(*dmg_type, *mag_type, s);
    return d_info;

}


std::vector<DamageInfo> damage_modifiers_from_string(std::string s, const std::string& sep) {

    std::vector<DamageInfo> dmods;

    // Only need to do anything if the string isn't empty
    if (!s.empty()) {
        boost::replace_all(s, "and ", "");
        std::vector<std::string> split_data = split(s, sep);
        dmods.reserve(split_data.size());

        //std::cout << "s is: " << s << std::endl;
        //std::cout << "split_data.size() is " << split_data.size() << std::endl;
        //std::cout << "dmods.size() is " << dmods.size() << std::endl;

        for (size_t i = 0; i < split_data.size(); i++) {
            dmods.push_back(identify_damage_info(split_data[i]));
        }
    }
    return dmods;

}

Monster parse_monster(const Json::Value& root, MonsterBuilder& b) {

    using namespace keys;

    // Get the basic info
    std::cout << "Monster name: " << root[name_k].asString() << std::endl;
    b.set_name(root[name_k].asString());
    b.set_size(Size::from_name(root[size_k].asString()));
    
    b.set_type(root[type_k].asString());
    b.set_subtype(root[subtype_k].asString());
    b.set_alignment(root[alignment_k].asString());
    b.set_armor_class(root[armor_class_k].asInt());
    b.set_hit_points(root[hit_points_k].asInt());
    b.set_hit_dice(DiceSet::from_string(root[hit_dice_k].asString()));
    b.set_challenge_rating(Fraction::from_string(root[challenge_rating_k].asString()));

    // Get the various speeds
    std::vector<std::string> speed_strs = split(root[speed_k].asString(), ", ");
    std::map<std::reference_wrapper<const SpeedType>,Distance, ref_wrap_comp> speeds;
    for (const std::string& s : speed_strs) {
        //std::cout << "Speed string: " << s << std::endl;
        std::vector<std::string> split_data = split(s, " ");
        //std::cout << "Split speed string size: " << split_data.size() << std::endl;
        if (split_data.size() == 2) { // Walking speed
            Distance dist = Distance::from_string(s);
            std::reference_wrapper<const SpeedType> speed_type {SpeedTypes::Walk};
            speeds.insert(std::make_pair(speed_type, dist));
        } else { // Other speed type
            split_data = split(s, " ", 2);
            Distance dist = Distance::from_string(split_data[1]);
            std::reference_wrapper<const SpeedType> speed_type = SpeedType::from_name(split_data[0]);
            speeds.insert(std::make_pair(speed_type, dist));
        }
    }
    b.set_speeds(speeds);

    // Get any speeds in alternate forms
    std::map<std::string,std::map<std::reference_wrapper<const SpeedType>,Distance,ref_wrap_comp>> alt_speeds;
    if (root.isMember(alt_speeds_k)) {
        
        Json::Value alt_speeds_json = root[alt_speeds_k];

        for (const Json::Value& alt_speed : alt_speeds_json) {
            std::string condition = alt_speed[condition_k].asString();
            std::vector<std::string> alt_speed_strs = split(alt_speed[speed_k].asString(), ", ");

            std::map<std::reference_wrapper<const SpeedType>,Distance,ref_wrap_comp> cond_speeds;
            for (const std::string& s : alt_speed_strs) {
                std::vector<std::string> split_data = split(s, " ");
                Distance dist;
                if (split_data.size() == 2) { // Walking speed
                    dist = Distance::from_string(s);
                    std::reference_wrapper<const SpeedType> speed_type {SpeedTypes::Walk};
                    cond_speeds.insert(std::make_pair(speed_type, dist));
                } else { // Other speed type
                    split_data = split(s, " ", 2);
                    std::reference_wrapper<const SpeedType> speed_type = SpeedType::from_name(split_data[0]);
                    dist = Distance::from_string(split_data[1]);
                    cond_speeds.insert(std::make_pair(speed_type, dist));
                }
            }
            alt_speeds.insert(std::make_pair(condition, cond_speeds));
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
    b.set_wisdom_save(int_if_member(root, wis_sv_k));
    b.set_charisma_save(int_if_member(root, chr_sv_k));

    // Skill bonuses
    std::map<std::reference_wrapper<const Skill>,int,ref_wrap_comp> skill_bonuses;
    for (auto skl : Skills::instances) {
        std::string lc_name(skl->name());
        to_lowercase(lc_name);
        if (root.isMember(lc_name)) {
            std::reference_wrapper sk_w(*skl);
            int bonus = root[lc_name].asInt();
            skill_bonuses.insert(std::make_pair(sk_w, bonus));
        }
    }
    b.set_skill_bonuses(skill_bonuses);

    // Other statistics
    b.set_perception(int_if_member(root, perception_k));

    // Vulnerabilities, resistances, immunities
    const std::string list_sep = ", ";
    //std::cout << "About to parse damage conditions" << std::endl;
    //std::cout << string_if_member(root, dmg_vuls_k) << std::endl;
    b.set_damage_vulnerabilities(damage_modifiers_from_string(string_if_member(root, dmg_vuls_k), list_sep));
    b.set_damage_resistances(damage_modifiers_from_string(string_if_member(root, dmg_rsts_k), list_sep));
    b.set_damage_immunities(damage_modifiers_from_string(string_if_member(root, dmg_imns_k), list_sep));
    //std::cout << "About to parse condition immunities" << std::endl;
    std::string data;
    std::vector<std::reference_wrapper<const Condition>> cond_imns;
    if ( !(data = root[cond_imns_k].asString()).empty() ) {
        std::vector<std::string> cond_strs = split(data, list_sep);
        cond_imns.reserve(cond_strs.size());
        for (const std::string& s : cond_strs) {
            cond_imns.emplace_back(Condition::from_lc_name(s));
        }
    }
    b.set_condition_immunities(cond_imns);

    // Senses and passive perception
    //std::cout << "About to parse senses and passive perception" << std::endl;
    std::map<std::reference_wrapper<const SenseType>, Distance, ref_wrap_comp> senses;
    int prcp  = 10;
    std::vector<std::string> senses_and_perception = split(root[senses_k].asString(), ", ");
    for (const std::string& s : senses_and_perception) {

        // If it's the passive perception
        std::vector<std::string> split_data = split(s, " ");
        if (starts_with(s, "passive Perception")) {
            prcp = std::stoi(split_data[2]);
        // Otherwise
        } else {
            split_data = split(s, " ", 2);
            Distance sense_range = Distance::from_string(split_data[1]);
            std::reference_wrapper<const SenseType> sense_type = SenseType::from_lc_name(split_data[0]);
            senses.insert(std::make_pair(sense_type, sense_range));
        }
    }
    b.set_passive_perception(prcp);
    b.set_senses(senses);

    // Languages (just a string for now, need to work on this)
    b.set_languages(root[languages_k].asString());

    // Special abilities
    std::vector<SpecialAbility> spcl_abls;
    if (root.isMember(spcl_abls_k)) {
        Json::Value spcl_abls_json = root[spcl_abls_k];
        spcl_abls.reserve(spcl_abls_json.size());

        for (const Json::Value& abl : spcl_abls_json) {
            std::string name = abl[name_k].asString();
            std::string desc = abl[description_k].asString();
            int atk_bonus = abl[atk_bonus_k].asInt();
            spcl_abls.emplace_back(name, desc, atk_bonus);
        }
    }
    b.set_special_abilities(spcl_abls);

    // Actions
    std::vector<Action> actions;
    if (root.isMember(actions_k)) {
        Json::Value actions_json = root[actions_k];
        actions.reserve(actions_json.size());
        for (const Json::Value& act : actions_json) {
            std::string name = act[name_k].asString();
            std::string desc = act[description_k].asString();
            int atk_bonus = act[atk_bonus_k].asInt();
            int dmg_bonus = int_if_member(act,dmg_bonus_k,0);
            std::string dmg_dice_str = act[dmg_dice_k].asString();
            DiceSet dset;
            std::cout << dmg_dice_str << std::endl;
            if (!dmg_dice_str.empty()) {
                dset = DiceSet::from_string(act[dmg_dice_k].asString());
            }
            actions.emplace_back(name, desc, atk_bonus, dset, dmg_bonus);
        }
    }
    b.set_actions(actions);

    // Legendary actions
    std::vector<LegendaryAction> leg_actions;
    if (root.isMember(leg_actions_k)) {
        Json::Value leg_acts_json = root[leg_actions_k];
        leg_actions.reserve(leg_acts_json.size());
        for (const Json::Value& lact : leg_acts_json) {
            std::string name = lact[name_k].asString();
            std::string desc = lact[description_k].asString();
            int atk_bonus = lact[atk_bonus_k].asInt();
            leg_actions.emplace_back(name, desc, atk_bonus);
        }
    }
    b.set_legendary_actions(leg_actions);

    // Image filename
    b.set_image_filename(string_if_member(root, "image_file", "Placeholder.jpeg"));

    // Build and return
    Monster m = b.build_and_reset();
    return m;

}

QVector<Monster> read_monster_file(QFile* qmonsterfile) {

    std::cout << qmonsterfile->fileName().toStdString() << std::endl;
    QTextStream in(qmonsterfile);
    std::string data = in.readAll().toStdString();

    Json::Value root;
    Json::CharReaderBuilder builder;
    Json::CharReader* reader = builder.newCharReader();
    std::string errors;
    reader->parse(data.c_str(), data.c_str() + data.size(), &root, &errors);

    QVector<Monster> monsters;
    monsters.resize(root.size());
    MonsterBuilder b;
    int idx = 0;
    for (const Json::Value& w : root) {

        // Skip the license
        if (w.isMember("license")) { continue; }
        Monster m = parse_monster(w, b);
        std::cout << "Created monster with name " << m.name() << std::endl;
        monsters[idx++] = m;
    }

    for (const Monster& m : monsters) {
        std::cout << m.name() << std::endl;
    }

    return monsters;
}
