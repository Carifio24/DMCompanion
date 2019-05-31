#ifndef RANGE_H
#define RANGE_H

#include "LengthUnit.h"
#include "Quantity.hpp"

#include <vector>

namespace DnD {

enum RangeType { Special=0, Self, Touch, Sight, Ranged, Unlimited };

class Range : public Quantity<RangeType, LengthUnit> {

    public:
        
        // Constructors
        Range(const RangeType& rt, const int& value, const LengthUnit& unit, const std::string& str="") : Quantity<RangeType, LengthUnit>(rt, value, unit, str) {}
        Range() : Range(Self, 0, LengthUnits::Foot) {}

        // Methods
        int length_in_feet() const { return base_value(); }
        std::string string() const;
        static Range fromString(const std::string& s);

        // Constant vector of names
        static const std::vector<std::string> typeNames;

};

} // end namespace DnD

#endif