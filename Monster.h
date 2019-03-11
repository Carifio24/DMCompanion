#ifndef MONSTER_H
#define MONSTER_H

#include "Enumerations.h"
#include "ability.h"
#include "action.h"
#include "alignment.h"
#include "fraction.h"
#include "damageinfo.h"

#include <utility>

struct Monster {

    // General properties
    std::string name;
    Size size;
    std::string type;
    std::string subtype;
    std::string alignment;
    Fraction challengeRating;

    // Combat statistics
    int armorClass;
    int hitPoints;
    std::pair<int, Die> hitDice;
    std::vector<std::pair<SpeedType,int>> speeds;
    std::vector<std::tuple<SpeedType,int,std::string>> alternateSpeeds;

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
    std::vector<DamageInfo> damageVulnerabilities;
    std::vector<DamageInfo> damageResistances;
    std::vector<DamageInfo> damageImmunities;
    std::vector<Condition> conditionImmunities;
    std::vector<std::pair<Sense,int>> senses;
    int passivePerception;
    std::string languages; // Will fix this later on
    std::vector<Ability> specialAbilities;
    std::vector<Action> actions;
    std::vector<Action> legendaryActions;

    ///// Member functions /////

    bool isImmuneTo(const DamageType& dtype);
    bool isImmuneTo(const Condition& condition);
    bool isResistantTo(const DamageType& dtype);
    bool isVulnerableTo(const DamageType& dtype);

    bool hasSpeed(const SpeedType& stype);
    bool hasAlternateSpeed(const SpeedType& stype);

    // To be added
    // bool speaks(const Language& language);
    // bool possibleAlignment(const Alignment& alignment);

};

#endif // MONSTER_H
