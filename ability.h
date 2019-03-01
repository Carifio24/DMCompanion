#ifndef ABILITY_H
#define ABILITY_H

struct Ability {

    // Properties
    std::string name;
    std::string desc;
    int attackBonus;

    // Constructor
    Ability(const std::string& nm, const std::string& dscr, const int& ab) : name(nm), desc(dscr), attackBonus(ab) {}

};

#endif // ABILITY_H
