#include "enummaps.h"

namespace DnD {

const std::map<CreatureType,std::string> creatureTypeNames = {
    {CreatureType::Aberration, "aberration"},
    {CreatureType::Beast, "beast"},
    {CreatureType::Celestial, "celestial"},
    {CreatureType::Construct, "construct"},
    {CreatureType::Dragon, "dragon"},
    {CreatureType::Elemental, "elemental"},
    {CreatureType::Fey, "fey"},
    {CreatureType::Fiend, "fiend"},
    {CreatureType::Giant, "giant"},
    {CreatureType::Humanoid, "humanoid"},
    {CreatureType::Monstrosity, "monstrosity"},
    {CreatureType::Ooze, "ooze"},
    {CreatureType::Plant, "plant"},
    {CreatureType::Undead, "undead"}
};

// Values giving the total numbers of elements of certain enum classes

const size_t N_CREATURE_TYPES = creatureTypeNames.size();

} // end namespace DnD