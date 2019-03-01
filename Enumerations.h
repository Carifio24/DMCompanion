#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include <vector>
#include <array>

/***** Dice *****/

enum class Die {
    d4=4, d6=6, d8=8, d10=10, d12=12, d20=20
};

/***** For spells *****/

enum class School {
	Abjuration=0, Conjuration, Divination, Enchantment, Evocation, Illusion, Necromancy, Transmutation
};

enum class CasterClass {
	Bard=0, Cleric, Druid, Paladin, Ranger, Sorcerer, Warlock, Wizard, ArcaneTrickster, EldritchKnight
};

enum class Subclass {
	Land=0, Lore, Draconic, Hunter, Life, Devotion, Berserker, Evocation, Fiend, Thief, OpenHand
};

enum class Sourcebook {
    PlayersHandbook=0, XanatharsGTE, SwordCoastAG
};

/***** For characters and monsters *****/

enum class Size {
    Tiny=0, Small, Medium, Large, Huge, Gargantuan
};

enum class CreatureType {
    Aberration=0, Beast, Celestial, Construct, Dragon, Elemental, Fey, Fiend, Giant, Humanoid, Monstrosity, Ooze, Plant, Undead
};



#endif
