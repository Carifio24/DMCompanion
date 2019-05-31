#include "TimeUnit.h"

#include <string>
#include <stdexcept>

namespace DnD {

const std::vector<const TimeUnit*> TimeUnit::Instances::instances = {
    &TimeUnits::Second,
    &TimeUnits::Round,
    &TimeUnits::Minute,
    &TimeUnits::Hour,
    &TimeUnits::Day,
    &TimeUnits::Year
};

const TimeUnit& TimeUnit::fromString(const std::string& s) {

    for (auto inst : TimeUnits::instances) {
        if ( (s == inst->name()) || (s == inst->plural_name()) || (s == inst->abbreviation()) ) {
            return *inst;
        }
    }

    throw std::runtime_error("Not a valid unit string");
}

} // end namespace DnD