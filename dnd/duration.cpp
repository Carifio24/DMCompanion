#include "duration.h"
#include "string_helpers.h"

#include <iterator>
#include <stdexcept>

namespace DnD {

// bool Duration::operator==(const Duration& other) const noexcept {
//     return time_in_seconds() == other.time_in_seconds();
// }

std::string Duration::string() const {
    if (!_str.empty()) {
        return _str;
    }

    if (quantity_type() != DurationTypes::Spanning) {
        return std::string(quantity_type().name());
    }

    std::string secs = (_value == 1) ? std::string(unit_type().name()) : std::string(unit_type().plural_name());
    return _value + " " + secs;
}

Duration Duration::from_string(std::string s) {
    static const std::string up_to = "Up to ";
    if (starts_with(s, up_to)) {
        auto it = s.begin();
        std::advance(it, up_to.length());
        s.erase(s.begin(), it);
    }
    if (starts_with(s, DurationTypes::Special.name())) {
        return Duration(DurationTypes::Special, 0, TimeUnits::Second, s);
    } else if (starts_with(s, DurationTypes::Instantaneous.name())) {
        return Duration(DurationTypes::Instantaneous, 0, TimeUnits::Second, s);
    } else if (starts_with(s, DurationTypes::UntilDispelled.name())) {
        return Duration(DurationTypes::UntilDispelled, 0, TimeUnits::Second, s);
    } 
    std::vector<std::string> s_split = split(s, " ");
    int t = std::stoi(s_split[0]);
    return Duration(DurationTypes::Spanning, t, TimeUnit::from_string(s_split[1]), s);
}

} // end namespace DnD