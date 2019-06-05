#include "distance.h"
#include "string_helpers.h"

#include <stdexcept>

namespace DnD {

bool Distance::operator==(const Distance& other) const noexcept {
    return this->length_in_feet() == other.length_in_feet();
}

std::string Distance::string() const {

    if (!_str.empty()) {
        return _str;
    }
    if (_type == DistanceTypes::Self) {
        if (_value > 0) {
            return "Self (" + std::to_string(_value) + " foot radius";
        } else {
            return "Self";
        }
    }
    if (_type == DistanceTypes::Distanced) {
        std::string ft = (_value == 1) ? std::string(LengthUnits::Foot.name()) : std::string(LengthUnits::Foot.plural_name());
        return _value + " " + ft;
    }
    return std::string(_type.name());
}

Distance Distance::from_string(const std::string& s) {
    if (starts_with(s, DistanceTypes::Touch.name())) {
        return Distance(DistanceTypes::Touch, 0, LengthUnits::Foot, s);
    } else if (starts_with(s, DistanceTypes::Special.name())) {
        return Distance(DistanceTypes::Special, 0, LengthUnits::Foot, s);
    } else if (starts_with(s, DistanceTypes::Sight.name())) {
        return Distance(DistanceTypes::Sight, 0, LengthUnits::Foot, s);
    } else if (starts_with(s, DistanceTypes::Unlimited.name())) {
        return Distance(DistanceTypes::Unlimited, 0, LengthUnits::Foot, s);
    } else if (starts_with(s, DistanceTypes::Self.name())) {
        std::vector<std::string> s_split = split(s, " ", 2);
        if (s_split.size() == 1) {
            return Distance(DistanceTypes::Self, 0, LengthUnits::Foot, s);
        } else {
            std::string dist_str = s_split[1];
            if (!starts_with(dist_str, "(") && !ends_with(s, ")")) {
                throw std::runtime_error("Error parsing radius of Self spell");
            }
            dist_str = dist_str.substr(1, dist_str.size() - 2);
            std::vector<std::string> dist_split = split(dist_str, " ");
            int length = std::stoi(dist_split[0]);
            return Distance(DistanceTypes::Self, length, LengthUnit::from_string(dist_split[1]), s);
        }
    } else {
        std::vector<std::string> s_split = split(s, " ");
        int length = std::stoi(s_split[0]);
        return Distance(DistanceTypes::Distanced, length, LengthUnit::from_string(s_split[1]), s);
    }
}

} // end namespace DnD