#ifndef SPELL_PARSE_H
#define SPELL_PARSE_H

#include <array>
#include <QFile>
#include <QVector>

#include <json/json.h>

#include "dnd/spell_builder.h"

std::array<bool,3> components(const Json::Value& comps);
DnD::Spell parse_spell(const Json::Value& root, DnD::SpellBuilder& b);
QVector<DnD::Spell> read_spell_file(QFile* qspellfile);


#endif
