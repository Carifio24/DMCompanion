#ifndef SPELL_PARSE_H
#define SPELL_PARSE_H

#include <array>

#include <json/json.h>

#include "SpellBuilder.h"

namespace DnD {

// The JSON file's keys
namespace keys {
const std::string name_k = "name";
const std::string page_k = "page";
const std::string range_k = "range";
const std::string casting_time_k = "casting_time";
const std::string level_k = "level";
const std::string concentration_k = "concentration";
const std::string ritual_k = "ritual";
const std::string description_k = "desc";
const std::string higher_level_k = "higher_level";
const std::string components_k = "components";
const std::string material_k = "material";
const std::string school_k = "school";
const std::string page_k = "page";
const std::string classes_k = "classes";
const std::string subclasses_k = "subclasses";
const std::string duration_k = "duration";
} // end namespace SpellKeys

std::array<bool,3> components(const Json::Value& comps);
Spell parse_spell(const Json::Value& root, SpellBuilder& b);
Spell parse_spell(const Json::Value& root);


} // end namespace DnD


#endif