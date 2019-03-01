#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include <vector>
#include <array>

// For convenience and to keep the code cleaner, we overload the unary operator+ to get the value of an enum
// So when you see something like +Tiny in the code, it's just getting the value of Tiny (i.e., 0)
// This is accomplished by casting the enum to its underlying type (note that the underlying type is declared for all of our enums)
template <typename T>
constexpr decltype(auto) operator+(T e) noexcept {
    return static_cast<std::underlying_type_t<T>>(e);
}

/***** Dice *****/

enum class Die {
    d4=4, d6=6, d8=8, d10=10, d12=12, d20=20
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

enum class Sourcebook: int {
    PlayersHandbook=0, XanatharsGTE, SwordCoastAG
};

/***** For characters and monsters *****/

enum class Size: int {
    Tiny=0, Small, Medium, Large, Huge, Gargantuan
};

enum class CreatureType: int {
    Aberration=0, Beast, Celestial, Construct, Dragon, Elemental, Fey, Fiend, Giant, Humanoid, Monstrosity, Ooze, Plant, Undead
};



#endif
