#ifndef SPELL_H
#define SPELL_H

#include "Enumerations.h"

#include <string>
#include <array>
#include <vector>

struct Spell {

    int index;
    std::string name;
    std::string description;
    std::string higherLevel;
    int page;
    std::string range;
    std::array<bool, 3> components;
    std::string material;
    bool ritual;
    std::string duration;
    bool concentration;
    std::string castingTime;
    int level;
    bool favorite;
    School school;
    Sourcebook sourcebook;
    std::vector<CasterClass> classes;
    std::vector<Subclass> subclasses;

    // Methods
    std::string componentsString() const;

};

#endif // SPELL_H

