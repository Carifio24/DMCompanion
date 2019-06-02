#ifndef MONSTER_H
#define MONSTER_H

#include "Enumerations.h"
#include "ability.h"
#include "action.h"
#include "alignment.h"
#include "fraction.h"
#include "damageinfo.h"

#include <utility>

class Monster {

    public:

        // Getters
        std::string name() const noexcept { return _name; }
        Size size() const noexcept { return _size; }


    private:

        // General properties
        const std::string _name;
        const Size _size;
        const std::string _type;
        const std::string _subtype;
        const std::string _alignment;
        const Fraction _challengeRating;

        // Combat statistics
        const int armorClass;
        const int hitPoints;
        const std::pair<int, Die> hitDice;
        const std::vector<std::pair<SpeedType,int>> speeds;
        const std::vector<std::tuple<SpeedType,int,std::string>> alternateSpeeds;

        // Ability scores
        const int strength;
        const int dexterity;
        const int constitution;
        const int intelligence;
        const int wisdom;
        const int charisma;

        // Saving throws
        const int strengthSave = 0;
        const int dexteritySave = 0;
        const int constitutionSave = 0;
        const int intelligenceSave = 0;
        const int wisdomSave = 0;
        const int charismaSave = 0;

        // Other attributes
        const int history;
        const int perception;
        const std::vector<DamageInfo> damageVulnerabilities;
        const std::vector<DamageInfo> damageResistances;
        const std::vector<DamageInfo> damageImmunities;
        const std::vector<Condition> conditionImmunities;
        const std::vector<std::pair<Sense,int>> senses;
        const int passivePerception;
        const std::string languages; // Will fix this later on
        const std::vector<Ability> specialAbilities;
        const std::vector<Action> actions;
        const std::vector<Action> legendaryActions;

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
