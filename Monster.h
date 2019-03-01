#ifndef MONSTER_H
#define MONSTER_H

#include "Enumerations.h"
#include "ability.h"
#include "action.h"

#include <utility>

struct Monster {

    // General properties
    std::string name;
    Size size;
    CreatureType type;
    std::string subtype;
    //Alignment alignment;
    int challengeRating;

    // Combat statistics
    int armorClass;
    int hitPoints;
    std::pair<int, Die> hitDice;
    std::vector<int> speeds;

    // Ability scores
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;

    // Saving throws
    int strengthSave = 0;
    int dexteritySave = 0;
    int constitutionSave = 0;
    int intelligenceSave = 0;
    int wisdomSave = 0;
    int charismaSave = 0;

    // Other attributes
    int history;
    int perception;
    std::string damageVulnerabilities;
    std::string damageResistances;
    std::string damageImmunities;
    std::string conditionImmunities;
    std::vector<std::string> senses;
    std::vector<std::string> languages;
    std::vector<Ability> specialAbilities;
    std::vector<Action> actions;
    std::vector<Action> legendaryActions;

};

#endif // MONSTER_H
