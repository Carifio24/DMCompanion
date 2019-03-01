#include "alignment.h"
#include "jstring.h"

#include <string>

#include <boost/algorithm/string.hpp>

std::string as_string(const Morality& m) {
    switch (m) {
    case Morality::Good:
        return "Good";
    case Morality::Neutral:
        return "Neutral";
    case Morality::Evil:
        return "Evil";
    }
}

std::string as_string(const Adherence& a) {
    switch (a) {
    case Adherence::Lawful:
        return "Lawful";
    case Adherence::Neutral:
        return "Neutral";
    case Adherence::Chaotic:
        return "Chaotic";
    }
}

// Morality and adherence as strings
Morality morality_from_string(std::string s) {
    boost::to_upper(s);
    if (s == "GOOD") { return Morality::Good; }
    if (s == "NEUTRAL") { return Morality::Neutral; }
    if (s == "EVIL") { return Morality::Evil; }
    throw std::runtime_error("Could not convert " + s + " to Morality");
}

Adherence adherence_from_string(std::string s) {
    boost::to_upper(s);
    if (s == "LAWFUL") { return Adherence::Lawful; }
    if (s == "NEUTRAL") { return Adherence::Neutral; }
    if (s == "CHAOTIC") { return Adherence::Chaotic; }
    throw std::runtime_error("Could not convert " + s + " to Adherence");
}

std::string Alignment::as_string() const {
    if (morality == Morality::Neutral && adherence == Adherence::Neutral) {
        return "True Neutral";
    } else {
        std::string s = ::as_string(adherence) + " " + ::as_string(morality);
        return s;
    }
}

Alignment Alignment::from_string(std::string s) {

    Alignment alignment;
    boost::to_upper(s);
    if (s == "TRUE NEUTRAL") {
        alignment.adherence = Adherence::Neutral;
        alignment.morality = Morality::Neutral;
    } else {
        std::vector<std::string> words = jstring::split_whitespace(s);
        alignment.adherence = adherence_from_string(words[0]);
        alignment.morality = morality_from_string(words[1]);
    }
    return alignment;
}
