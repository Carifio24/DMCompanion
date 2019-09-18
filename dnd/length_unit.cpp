#include "length_unit.h"

#include <iostream>

namespace DnD {

const LengthUnitImpl& LengthUnitImpl::from_string(const std::string& s) {
    // Check whether the name agrees with any of the cases
    for (auto inst : LengthUnitImpl::Instances::instances) {
        if ( (s == inst->_name ) || (s == inst->_pl_name) || ( s == inst->_abbr) || ( s == (std::string(inst->abbreviation()) + ".")) ) {
            return *inst;
        }
    }
    throw std::runtime_error("Not a valid LengthUnit string -- " + s);
}

} // end namespace DnD