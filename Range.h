#ifndef RANGE_H
#define RANGE_H

#include "LengthUnit.h"
#include "Quantity.hpp"

enum class RangeType { Special=0, Self, Touch, Sight, Ranged, Unlimited };

class Range : Quantity<RangeType, LengthUnit> {

    public:
        
        Range(const RangeType& rt, const int& value, const LengthUnit& unit, const std::string& str="") : Quantity<RangeType, LengthUnit>(rt, value, unit, str) {}
        
        int length_in_feet() const { return baseValue(); }
        std::string string() const;
        static Range fromString(const std::string& s);

};

#endif