#ifndef ABILITY_H
#define ABILITY_H

#include <string>

struct Ability {

    // Properties
    std::string name;
    std::string desc;
    int attackBonus;

    // Constructors
    Ability(const std::string& nm, const std::string& dscr, const int& ab) : name(nm), desc(dscr), attackBonus(ab) {}

    // Default constructor
    Ability() : Ability("", "", 0) {}


};

#endif // ABILITY_H
