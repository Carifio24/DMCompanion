#include "ability.h"
#include <iostream>

// JSON constructor
Ability::Ability(const Json::Value& root) {
    try {
        name = root["name"].asString();
        desc = root["name"].asString();
        attackBonus = root["attack_bonus"].asInt();
    } catch (Json::LogicError& e) {
        std::cout << e.what() << std::endl;
    }
}
