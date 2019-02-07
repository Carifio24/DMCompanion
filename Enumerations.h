#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include <vector>
#include <array>

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

#endif
