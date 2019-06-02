#ifndef SPELL_PARSE_H
#define SPELL_PARSE_H

#include <array>

#include <json/json.h>

#include "SpellBuilder.h"

namespace DnD {

    std::array<bool,3> components(const Json::Value& comps);
    Spell parse_spell(const Json::Value& root, const SpellBuilder& b)
    Spell parse_spell(const Json::Value& root);


} // end namespace DnD


#endif