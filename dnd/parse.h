#ifndef PARSE_H
#define PARSE_H

#include <fstream>
#include <vector>
#include <string>
#include <array>
#include "enumerations.h"
#include "spell.h"
#include "monster.h"
#include "enummaps.h"
#include "jsoncpp/json/json.h"
#include <QFile>

// General-purpose methods

bool yn_to_bool(const std::string& yn);

std::string bool_to_yn(const bool& yn);

std::string capitalized(std::string s);

int int_if_member(const Json::Value& root, const std::string& field, const int& defaultValue=0);

std::string string_if_member(const Json::Value& root, const std::string& field, const std::string& defaultValue="");

std::pair<int,Die> dice_from_string(const std::string& s);

DamageInfo identify_damage_info(const std::string& s, const std::map<DamageType,std::string>& damageTypes=damageTypeNames);

std::vector<DamageInfo> damage_modifiers_from_string(std::string s, const std::string& sep);

// Spellbook-specific methods

std::array<bool,3> components(const Json::Value& comps);

School school_from_name(const std::string& name);

Spell parse_spell(const Json::Value& root);

std::vector<Spell> read_spellfile(QFile* qspellfile);

// Monster manual methods

//Size size_from_text(const std::string& s);

Monster parse_monster(const Json::Value& root);

std::vector<Monster> read_monsterfile(QFile* qmonsterfile);

// Template implementations
#include "Parse.tpp"

#endif
