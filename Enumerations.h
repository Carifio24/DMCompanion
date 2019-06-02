#ifndef CLASSES_H
#define CLASSES_H

//#include <variant>
#include <type_traits>

#include "EnumHelpers.hpp"

/***** Dice *****/

enum class Die: int {
    d4=4, d6=6, d8=8, d10=10, d12=12, d20=20
};

/***** For damage and statuses *****/

enum class DamageType: int {
    Damage=0, Acid, Bludgeoning, Cold, Fire, Force, Lightning, Necrotic, Piercing, Poison, Psychic, Radiant, Slashing, Thunder
};

enum class MagicType: int {
    Any=0, Magical, Nonmagical
};

enum class Condition: int {
    Blinded=0, Charmed, Deafened, Exhaustion, Fatigued, Frightened, Grappled, Incapacitated, Invisible, Paralyzed, Petrified, Poisoned, Prone, Restrained, Stunned, Unconscious
};


/***** For spells *****/

enum class School: int {
	Abjuration=0, Conjuration, Divination, Enchantment, Evocation, Illusion, Necromancy, Transmutation
};

enum class CasterClass: int {
	Bard=0, Cleric, Druid, Paladin, Ranger, Sorcerer, Warlock, Wizard, ArcaneTrickster, EldritchKnight
};

enum class Subclass: int {
	Land=0, Lore, Draconic, Hunter, Life, Devotion, Berserker, Evocation, Fiend, Thief, OpenHand
};

/***** For characters and monsters *****/

enum class Size: int {
    Tiny=0, Small, Medium, Large, Huge, Gargantuan
};

enum class CreatureType: int {
    Aberration=0, Beast, Celestial, Construct, Dragon, Elemental, Fey, Fiend, Giant, Humanoid, Monstrosity, Ooze, Plant, Undead
};

enum class Sense: int {
    Blindsight=0, Darkvision, Tremorsense, Truesight
};

/***** For languages *****/

enum class CommonLanguage: int {
    Common=0, Dwarvish, Elvish, Giant, Gnomish, Goblin, Halfling, Orc
};

enum class ExoticLanguage: int {
    Abyssal=0, Celestial, DeepSpeech, Draconic, Druidic, Infernal, Primordial, Sylvan, Undercommon
};

// If the hierarchical structure for languages ever becomes nontrivial,
// a wrapper class to allow inheritance would probably be the way to go
// But with only two flavors, it doesn't seem worth the boilerplate
// So we'll use a tagged union instead for Language, which encompasses both

//using Language = std::variant<CommonLanguage,ExoticLanguage>;
//const int COMMON_LANG_INDEX = 0;
//const int EXOTIC_LANG_INDEX = 1;



#endif
