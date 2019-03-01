#ifndef ACTION_H
#define ACTION_H

#include "Enumerations.h"

struct Action {

    // Properties
    std::string name;
    std::string desc;
    int attackBonus;
    std::vector<std::pair<int, Die>> damageDice;
    int damageBonus;

    // Constructors
    Action(const std::string& name, const std::string& desc, const int& attackBonus, const std::vector<std::pair<int, Die>> damageDice, const int& damageBonus)
        : name(name), desc(desc), attackBonus(attackBonus), damageDice(damageDice), damageBonus(damageBonus) {}

    // Default values for damageDice and damageBonus
    Action(const std::string& name, const std::string& desc, const int& attackBonus) : Action(name, desc, attackBonus, {{0,Die::d4}}, 0) {}


};

#endif // ACTION_H
