#ifndef MONSTER_PARSE_H
#define MONSTER_PARSE_H

#include <DnD/monster.h>
#include <DnD/monster_builder.h>

#include <json/json.h>

#include <QFile>
#include <QVector>

DnD::DamageInfo identify_damage_info(std::string s);
std::vector<DnD::DamageInfo> damage_modifiers_from_string(std::string s, const std::string& sep);
DnD::Monster parse_monster(const Json::Value& root, const DnD::MonsterBuilder& b);
QVector<DnD::Monster> read_monster_file(QFile* qmonsterfile);

#endif
