#ifndef CLASSES_H
#define CLASSES_H

//#include <variant>
#include <type_traits>

namespace DnD {

/***  Get underlying value with operator*  ***/
// For convenience, and to keep the code cleaner, we overload the dereferencing operator to get the value of an enum
// So when you see something like *Tiny in the code, it's just getting the value of Tiny (i.e., 0)
// This is mostly useful for enums where the value is actually meaningful (i.e. Die), but it's a nice option to have regardless
// This is accomplished by casting the enum to its underlying type (note that the underlying type is declared for all of our enums)
template <typename T, typename = std::enable_if_t<std::is_enum_v<T>> >
constexpr decltype(auto) operator*(T e) noexcept {
    return static_cast<std::underlying_type_t<T>>(e);
}

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

/***** For spells *****/

enum class Subclass: int {
	Land=0, Lore, Draconic, Hunter, Life, Devotion, Berserker, Evocation, Fiend, Thief, OpenHand
};

/***** For characters and monsters *****/

enum class CreatureType: int {
    Aberration=0, Beast, Celestial, Construct, Dragon, Elemental, Fey, Fiend, Giant, Humanoid, Monstrosity, Ooze, Plant, Undead
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


} // end namespace DnD

#endif
