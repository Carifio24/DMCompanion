#ifndef ABILITY_H
#define ABILITY_H

#include <jsoncpp/json/json.h>

struct Ability {

    // Properties
    std::string name;
    std::string desc;
    int attackBonus;

    // Constructors
    Ability(const std::string& nm, const std::string& dscr, const int& ab) : name(nm), desc(dscr), attackBonus(ab) {}
    Ability(const Json::Value& root);

    // Default constructor
    Ability() : Ability("", "", 0) {}


};

#endif // ABILITY_H
