#include <vector>
#include <string>
#include <fstream>
#include <array>
#include <exception>
#include <iostream>
#include <locale>
#include <utility>
#include <regex>

#include <assert.h>

#include "StringHelpers.h"
#include "JsonHelpers.h"
#include "Enumerations.h"
#include "Parse.h"
#include "Monster.h"
#include "enummaps.h"
#include "damageinfo.h"

#include <boost/algorithm/string/replace.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string.hpp>

#include <QTextStream>

// General-purpose methods

std::pair<int,Die> dice_from_string(const std::string& s) {
    std::vector<std::string> dice_vals = jstring::split(s, "d");
    int n_dice = std::stoi(dice_vals[0]);
    Die dtype = static_cast<Die>(std::stoi(dice_vals[1]));
    auto dice = std::make_pair(n_dice, dtype);
    return dice;
}


std::vector<Spell> read_spellfile(QFile* qspellfile) {

    std::cout << qspellfile->fileName().toStdString() << std::endl;
    QTextStream in(qspellfile);
    std::string data = in.readAll().toStdString();

	Json::Value root;
	Json::CharReaderBuilder builder;
	Json::CharReader* reader = builder.newCharReader();
	std::string errors;
	reader->parse(data.c_str(), data.c_str() + data.size(), &root, &errors);

	std::vector<Spell> spells;
	for (Json::Value& w : root) {
		spells.push_back(parse_spell(w));
	}
	spells.shrink_to_fit();
	return spells;
}


DamageInfo identify_damage_info(const std::string& s, const std::map<DamageType,std::string>& damageTypes) {

    // Make the string all lowercase
    std::string s_lower = boost::to_lower_copy(s);

    // Get the damage type
    DamageInfo dInf;
    dInf.text = s;
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
        dInf.magic_type = MagicType::Magical;
    } else {
        dInf.magic_type = MagicType::Any;
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


Monster parse_monster(const Json::Value& root) {

    // Create the monster
    Monster m;

    // Get the basic info
    m.name = root["name"].asString();
    std::cout << "The monster name is " << m.name << std::endl;
    m.size = enum_from_name<Size>(sizeNames, root["size"].asString());
    std::string creatureType = root["type"].asString();
    //m.type = enum_from_name<CreatureType>(creatureTypeNames, creatureType);
    m.type = root["type"].asString();
    m.subtype = root["subtype"].asString();
    //m.alignment = Alignment::from_string(root["alignment"].asString());
    m.alignment = root["alignment"].asString();
    m.armorClass = root["armor_class"].asInt();
    m.hitPoints = root["hit_points"].asInt();
    m.hitDice = dice_from_string(root["hit_dice"].asString());
    m.challengeRating = Fraction::from_string(root["challenge_rating"].asString());

    // Get the various speeds
    std::vector<std::string> speed_strs = jstring::split(root["speed"].asString(), ", ");
    for (const std::string& s : speed_strs) {
        std::cout << "Speed string: " << s << std::endl;
        std::vector<std::string> split_data = jstring::split(s, " ");
        std::cout << "Split speed string size: " << split_data.size() << std::endl;
        if (split_data.size() == 2) { // Walking speed
            int speed_value = std::stoi(split_data[0]);
            m.speeds.push_back(std::make_pair(SpeedType::Walking, speed_value));
        } else { // Other speed type
            int speed_value = std::stoi(split_data[1]);
            SpeedType speed_type = enum_from_name<SpeedType>(speedTypeNames, split_data[0]);
            m.speeds.push_back(std::make_pair(speed_type, speed_value));
        }
    }

    // Get any speeds in alternate forms
    if (root.isMember("alternate_speeds")) {
        Json::Value alt_speeds_json = root["alternate_speeds"];

        for (const Json::Value& alt_speed : alt_speeds_json) {
            std::string alt_speed_condition = alt_speed["condition"].asString();
            std::vector<std::string> alt_speed_strs = jstring::split(alt_speed["speed"].asString(), ", ");

            for (const std::string& s : alt_speed_strs) {
                std::vector<std::string> split_data = jstring::split(s, " ");
                if (split_data.size() == 2) { // Walking speed
                    int speed_value = std::stoi(split_data[0]);
                    std::tuple<SpeedType,int,std::string> speedInfo{SpeedType::Walking, speed_value, alt_speed_condition};
                    m.alternateSpeeds.push_back(speedInfo);
                } else { // Other speed type
                    int speed_value = std::stoi(split_data[1]);
                    SpeedType speed_type = enum_from_name<SpeedType>(speedTypeNames, split_data[0]);
                    std::tuple<SpeedType,int,std::string> speedInfo{speed_type, speed_value, alt_speed_condition};
                    m.alternateSpeeds.push_back(speedInfo);
                }
            }
        }
    }

    // Ability scores
    m.strength = root["strength"].asInt();
    m.dexterity = root["dexterity"].asInt();
    m.constitution = root["constitution"].asInt();
    m.intelligence = root["intelligence"].asInt();
    m.wisdom = root["wisdom"].asInt();
    m.charisma = root["charisma"].asInt();

    // Saving throw modifiers
    m.strengthSave =  int_if_member(root, "strength_save");
    m.dexteritySave = int_if_member(root, "dexterity_save");
    m.constitutionSave = int_if_member(root, "constitution_save");
    m.intelligenceSave = int_if_member(root, "intelligence_save");
    m.wisdomSave = int_if_member(root, "wisdom_save");
    m.charismaSave = int_if_member(root, "charisma_save");

    // Other statistics
    m.history = int_if_member(root, "history");
    m.perception = int_if_member(root, "perception");

    // Vulnerabilities, resistances, immunities
    std::string list_sep = ", ";
    std::cout << "About to parse damage conditions" << std::endl;
    std::cout << string_if_member(root, "damage_vulnerabilities") << std::endl;
    m.damageVulnerabilities = damage_modifiers_from_string(string_if_member(root, "damage_vulnerabilities"), list_sep);
    m.damageResistances = damage_modifiers_from_string(string_if_member(root, "damage_resistances"), list_sep);
    m.damageImmunities = damage_modifiers_from_string(string_if_member(root, "damage_immunities"), list_sep);
    std::cout << "About to parse condition immunities" << std::endl;
    std::string data;
    if ( !(data = root["condition_immunities"].asString()).empty() ) {
        std::cout << data << std::endl;
        m.conditionImmunities = enum_vector_from_names<Condition>(conditionNames, jstring::split(data, list_sep));
    }

    // Senses and passive perception
    std::vector<std::string> senses_and_perception = jstring::split(root["senses"].asString(), ", ");
    for (const std::string& s : senses_and_perception) {

        // If it's the passive perception
        std::vector<std::string> split_data = jstring::split(s, " ");
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
    m.languages = root["languages"].asString();

    // Special abilities
    if (root.isMember("special_abilities")) {
        m.specialAbilities = json_array_to_vector<Ability>(root["special_abilities"]);
    }

    // Actions and legendary actions
    if (root.isMember("actions")) {
        m.actions = json_array_to_vector<Action>(root["actions"]);
    }
    if (root.isMember("legendary_actions")) {
        m.legendaryActions = json_array_to_vector<Action>(root["legendary_actions"]);
    }

    return m;

}

std::vector<Monster> read_monsterfile(QFile* qmonsterfile) {

    std::cout << qmonsterfile->fileName().toStdString() << std::endl;
    QTextStream in(qmonsterfile);
    std::string data = in.readAll().toStdString();

    Json::Value root;
    Json::CharReaderBuilder builder;
    Json::CharReader* reader = builder.newCharReader();
    std::string errors;
    reader->parse(data.c_str(), data.c_str() + data.size(), &root, &errors);

    std::vector<Monster> monsters;
    for (Json::Value& w : root) {

        // Skip the license
        if (w.isMember("license")) { continue; }

        monsters.push_back(parse_monster(w));
    }
    monsters.shrink_to_fit();

    for (const Monster& m : monsters) {
        std::cout << m.name << std::endl;
    }

    return monsters;
}
