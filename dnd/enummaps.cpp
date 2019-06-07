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

const std::map<DamageType,std::string> damageTypeNames = {
    {DamageType::Damage, "damage"},
    {DamageType::Acid, "acid"},
    {DamageType::Bludgeoning, "bludgeoning"},
    {DamageType::Cold, "cold"},
    {DamageType::Fire, "fire"},
    {DamageType::Force, "force"},
    {DamageType::Lightning, "lightning"},
    {DamageType::Necrotic, "necrotic"},
    {DamageType::Piercing, "piercing"},
    {DamageType::Poison, "poison"},
    {DamageType::Psychic, "psychic"},
    {DamageType::Radiant, "radiant"},
    {DamageType::Slashing, "slashing"},
    {DamageType::Thunder, "thunder"}
};

// Values giving the total numbers of elements of certain enum classes

const size_t N_CREATURE_TYPES = creatureTypeNames.size();

const size_t N_DAMAGE_TYPES = damageTypeNames.size();

} // end namespace DnD