#include "monster.h"

namespace DnD {

bool Monster::has_speed(const SpeedType& stype) const noexcept {
    return _speeds.find(stype) != _speeds.end();
}

int Monster::speed_value(const SpeedType& stype) const noexcept {
    auto it = _speeds.find(stype);
    if (it == _speeds.end()) {
        return 0;
    }
    return it->second.length_in_feet();
}

} // end namespace DnD