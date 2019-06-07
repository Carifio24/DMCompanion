#ifndef SPELL_PARSE_H
#define SPELL_PARSE_H

#include <array>

#include <json/json.h>

#include "keys.h"
#include "spell_builder.h"

namespace DnD {

std::array<bool,3> components(const Json::Value& comps);
Spell parse_spell(const Json::Value& root, SpellBuilder& b);


} // end namespace DnD


#endif