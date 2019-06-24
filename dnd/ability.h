#ifndef ABILITY_H
#define ABILITY_H

#include <string>

namespace DnD {

struct Ability {

    // Properties
    std::string name;
    std::string desc;
    int attack_bonus;

    // Constructors
    Ability(const std::string& nm, const std::string& dscr, const int ab) : name(nm), desc(dscr), attack_bonus(ab) {}

    // Default constructor
    Ability() : Ability("", "", 0) {}


};

} // end namespace DnD

#endif // ABILITY_H
