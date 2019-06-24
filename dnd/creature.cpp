#include "creature.h"

namespace DnD {

bool Creature::has_speed(const SpeedType& stype) {
    return _speeds.find(stype) != _speeds.end();
}

bool Creature::has_alternate_speed(const SpeedType& stype) {
    return _alt_speeds.find(stype) != _alt_speeds.end();
}

int Creature::speed_value(const SpeedType& stype) {
    auto it = _speeds.find(stype);
    if (it == _speeds.end()) {
        return 0;
    }
    return it->second.length_in_feet();
}

int Creature::alternate_speed_value(const SpeedType& stype) {
    auto it = _alt_speeds.find(stype);
    if (it == _alt_speeds.end()) {
        return 0;
    }
    return it->second.first.length_in_feet();
}

std::string Creature::alternate_speed_condition(const SpeedType& stype) {
    auto it = _alt_speeds.find(stype);
    if (it == _alt_speeds.end()) {
        return 0;
    }
    return it->second.second;
}

} // end namespace DnD