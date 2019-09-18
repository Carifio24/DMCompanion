#ifndef MONSTER_PARSE_H
#define MONSTER_PARSE_H

#include "dnd/feature.h"
#include "dnd/monster.h"
#include "dnd/monster_builder.h"

#include <json/json.h>

DnD::DamageInfo identify_damage_info(std::string s);
std::vector<DnD::DamageInfo> damage_modifiers_from_string(std::string s, const std::string& sep);
DnD::Monster parse_monster(const Json::Value& root, DnD::MonsterBuilder& b);
std::vector<DnD::Feature> features_from_json_entry(const Json::Value& json, const std::string& key);

#endif
