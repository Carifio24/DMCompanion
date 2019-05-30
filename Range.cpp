#include "Range.h"
#include "StringHelpers.h"

std::string Range::string() const {
    if (!_str.empty()) {
        return _str;
    }
    switch (_type) {
        case Touch:
            return "Touch";
        case Special:
            return "Special";
        case Unlimited:
            return "Unlimited";
        case Self: {
            if (_value > 0) {
                return "Self (" + std::to_string(_value) + " foot radius";
            } else {
                return "Self";
            }
        }
        case Ranged: {
            std::string ft = (_value == 1) ? LengthUnits.Foot.name() : LengthUnits.Foot.plural_name();
            return _value + " " + ft;
        }
        default:
            return ""; // Unreachable, switch exhausts the enum
    }
}

Range Range::fromString(const std::string& s) {
    if (starts_with())
}