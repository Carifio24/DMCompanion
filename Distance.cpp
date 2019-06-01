#include "Distance.h"
#include "StringHelpers.h"
#include "EnumHelpers.hpp"

#include <stdexcept>

namespace DnD {

const std::vector<std::string> Distance::typeNames = { "Special", "Self", "Touch", "Sight", "Distanced", "Unlimited" };

std::string Distance::string() const {
    if (!_str.empty()) {
        return _str;
    }
    switch (_type) {
        case Touch:
            return "Touch";
        case Special:
            return "Special";
        case DistanceType::Unlimited:
            return "Unlimited";
        case Sight:
            return "Sight";
        case Self: {
            if (_value > 0) {
                return "Self (" + std::to_string(_value) + " foot radius";
            } else {
                return "Self";
            }
        }
        case Distanced: {
            std::string ft = (_value == 1) ? std::string(LengthUnits::Foot.name()) : std::string(LengthUnits::Foot.plural_name());
            return _value + " " + ft;
        }
        default:
            return ""; // Unreachable, switch exhausts the enum
    }
}

Distance Distance::fromString(const std::string& s) {
    if (starts_with(s, typeNames[*Touch])) {
        return Distance(Touch, 0, LengthUnits::Foot, s);
    } else if (starts_with(s, typeNames[*Special])) {
        return Distance(Special, 0, LengthUnits::Foot, s);
    } else if (starts_with(s, typeNames[*Sight])) {
        return Distance(Sight, 0, LengthUnits::Foot, s);
    } else if (starts_with(s, typeNames[*Unlimited])) {
        return Distance(Unlimited, 0, LengthUnits::Foot, s);
    } else if (starts_with(s, typeNames[*Self])) {
        std::vector<std::string> s_split = split(s, " ", 2);
        if (s_split.size() == 1) {
            return Distance(Self, 0, LengthUnits::Foot, s);
        } else {
            std::string dist_str = s_split[1];
            if (!starts_with(dist_str, "(") && !ends_with(s, ")")) {
                throw std::runtime_error("Error parsing radius of Self spell");
            }
            dist_str = dist_str.substr(1, dist_str.size() - 2);
            std::vector<std::string> dist_split = split(dist_str, " ");
            int length = std::stoi(dist_split[0]);
            return Distance(Self, length, LengthUnit::fromString(dist_split[1]), s);
        }
    } else {
        std::vector<std::string> s_split = split(s, " ");
        int length = std::stoi(s_split[0]);
        return Distance(Distanced, length, LengthUnit::fromString(s_split[1]), s);
    }
}

} // end namespace DnD