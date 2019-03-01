#ifndef ALIGNMENT_H
#define ALIGNMENT_H

#include <string>

enum class Morality {
    Good=0, Neutral, Evil
};

enum class Adherence {
    Lawful=0, Neutral, Chaotic
};

// Morality and adherence as strings
std::string to_string(const Morality& m);
std::string to_string(const Adherence& a);

// Morality and adherence from strings
Morality morality_from_string(std::string s);
Adherence adherence_from_string(std::string s);

struct Alignment {
    Morality morality;
    Adherence adherence;

    // Print the alignment as a string
    std::string as_string() const;

    // Get from a string
    static Alignment from_string(std::string s);
};

#endif // ALIGNMENT_H
