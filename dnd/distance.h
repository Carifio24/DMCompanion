#ifndef DISTANCE_H
#define DISTANCE_H

#include "length_unit.h"
#include "quantity.hpp"
#include "distance_type.h"

#include <vector>

namespace DnD {

class Distance : public Quantity<DistanceType, LengthUnit> {

    public:
        
        // Constructors
        Distance(const DistanceType& rt, const int& value, const LengthUnit& unit, const std::string& str="") : Quantity<DistanceType, LengthUnit>(rt, value, unit, str) {}
        Distance() : Distance(DistanceTypes::Self, 0, LengthUnits::Foot) {}

        bool operator==(const Distance& other) const noexcept;

        // Methods
        int length_in_feet() const noexcept { return base_value(); }
        std::string string() const;
        static Distance from_string(const std::string& s);



};

} // end namespace DnD

#endif