#include "length_unit.h"

namespace DnD {

const LengthUnit& LengthUnit::from_string(const std::string& s) {
    // Check whether the name agrees with any of the cases
    for (auto inst : LengthUnit::Instances::instances) {
        if ( (s == inst->_name ) || (s == inst->plural_name()) || ( s == inst->abbreviation()) || ( s == std::string(inst->abbreviation()) + ".") ) {
            return *inst;
        }
    }
    throw std::runtime_error("Not a valid string");
}

} // end namespace DnD