#include "LengthUnit.h"

#include <string>
#include <stdexcept>

namespace DnD {

const std::vector<const LengthUnit*> LengthUnits::instances = {
    &LengthUnits::Foot,
    &LengthUnits::Mile
};

const LengthUnit& LengthUnit::fromString(const std::string& s) {

    for (auto inst : LengthUnits::instances) {
        if ( (s == inst->name()) || (s == inst->plural_name()) || (s == inst->abbreviation()) ) {
            return *inst;
        }
    }

    throw std::runtime_error("Not a valid unit string");
}

} // end namespace DnD