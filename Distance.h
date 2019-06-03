#ifndef DISTANCE_H
#define DISTANCE_H

#include "LengthUnit.h"
#include "Quantity.hpp"

#include <vector>

namespace DnD {

enum DistanceType { Special=0, Self, Touch, Sight, Distanced, Unlimited };

class Distance : public Quantity<DistanceType, LengthUnit> {

    public:
        
        // Constructors
        Distance(const DistanceType& rt, const int& value, const LengthUnit& unit, const std::string& str="") : Quantity<DistanceType, LengthUnit>(rt, value, unit, str) {}
        Distance() : Distance(Self, 0, LengthUnits::Foot) {}

        // Methods
        int length_in_feet() const noexcept { return base_value(); }
        std::string string() const;
        static Distance fromString(const std::string& s);

        // Constant vector of names
        static const std::vector<std::string> typeNames;

};

} // end namespace DnD

#endif