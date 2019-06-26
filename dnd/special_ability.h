#ifndef SPECIAL_ABILITY_H
#define SPECIAL_ABILITY_H

#include <string>

namespace DnD {

struct SpecialAbility {

    // Properties
    std::string name;
    std::string desc;
    int attack_bonus;

    // Constructors
    SpecialAbility(const std::string& nm, const std::string& dscr, const int ab) : name(nm), desc(dscr), attack_bonus(ab) {}

    // Default constructor
    SpecialAbility() : SpecialAbility("", "", 0) {}


};

} // end namespace DnD

#endif // ABILITY_H
