#include "enummaps.h"

const std::map<School,std::string> schoolNames = {
    {School::Abjuration, "Abjuration"},
    {School::Conjuration, "Conjuration"},
    {School::Divination, "Divination"},
    {School::Enchantment, "Enchantment"},
    {School::Evocation, "Evocation"},
    {School::Illusion, "Illusion"},
    {School::Necromancy, "Necromancy"},
    {School::Transmutation, "Transmutation"}
};

const std::map<CasterClass,std::string> casterNames = {
    {CasterClass::Bard, "Bard"},
    {CasterClass::Cleric, "Cleric"},
    {CasterClass::Druid, "Druid"},
    {CasterClass::Paladin, "Paladin"},
    {CasterClass::Distancer, "Distancer"},
    {CasterClass::Sorcerer, "Sorcerer"},
    {CasterClass::Warlock, "Warlock"},
    {CasterClass::Wizard, "Wizard"}
};

const std::map<Subclass,std::string> subclassNames = {
    {Subclass::Land, "Land"},
    {Subclass::Lore, "Lore"},
    {Subclass::Life, "Life"},
    {Subclass::Devotion, "Devotion"},
    {Subclass::Fiend, "Fiend"}
};

const std::map<Sourcebook,std::string> sourcebookNames = {
    {Sourcebook::PlayersHandbook, "Player's Handbook"},
    {Sourcebook::XanatharsGTE, "Xanathar's Guide to Everything"},
    {Sourcebook::SwordCoastAG, "Sword Coast Adventurer's Guide"}
};

const std::map<Sourcebook,std::string> sourcebookCodes = {
    {Sourcebook::PlayersHandbook, "PHB"},
    {Sourcebook::XanatharsGTE, "XGE"},
    {Sourcebook::SwordCoastAG, "SCAG"}
};

const std::map<Size,std::string> sizeNames = {
    {Size::Tiny, "Tiny"},
    {Size::Small, "Small"},
    {Size::Medium, "Medium"},
    {Size::Large, "Large"},
    {Size::Huge, "Huge"},
    {Size::Gargantuan, "Gargantuan"}
};

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

const std::map<SpeedType,std::string> speedTypeNames = {
    {SpeedType::Walking, "walk"},
    {SpeedType::Burrow, "burrow"},
    {SpeedType::Climb, "climb"},
    {SpeedType::Fly, "fly"},
    {SpeedType::Swim, "swim"}
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

const std::map<Condition,std::string> conditionNames = {
    {Condition::Blinded, "blinded"},
    {Condition::Charmed, "charmed"},
    {Condition::Deafened, "deafened"},
    {Condition::Exhaustion, "exhaustion"},
    {Condition::Fatigued, "fatigued"},
    {Condition::Frightened, "frightened"},
    {Condition::Grappled, "grappled"},
    {Condition::Incapacitated, "incapacitated"},
    {Condition::Invisible, "invisible"},
    {Condition::Paralyzed, "paralyzed"},
    {Condition::Petrified, "petrified"},
    {Condition::Poisoned, "poisoned"},
    {Condition::Prone, "prone"},
    {Condition::Restrained, "restrained"},
    {Condition::Stunned, "stunned"},
    {Condition::Unconscious, "unconscious"}
};

const std::map<Sense,std::string> senseNames = {
    {Sense::Blindsight, "blindsight"},
    {Sense::Darkvision, "darkvision"},
    {Sense::Tremorsense, "tremorsense"},
    {Sense::Truesight, "truesight"}
};

// Values giving the total numbers of elements of certain enum classes

const size_t N_SCHOOLS = schoolNames.size();

const size_t N_CASTERS = casterNames.size();

const size_t N_SUBCLASSES = subclassNames.size();

const size_t N_SOURCES = sourcebookNames.size();

const size_t N_SIZES = sizeNames.size();

const size_t N_CREATURE_TYPES = creatureTypeNames.size();

const size_t N_SPEED_TYPES = speedTypeNames.size();

const size_t N_DAMAGE_TYPES = damageTypeNames.size();

const size_t N_CONDITIONS = conditionNames.size();

const size_t N_SENSES = senseNames.size();
