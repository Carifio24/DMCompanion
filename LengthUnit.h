#ifndef LENGTH_UNIT_H
#define LENGTH_UNIT_H

#include "Unit.h"

#include <vector>

namespace DnD {

class LengthUnit : public Unit {

    public:
        // The class instances
        struct Instances;

        // Get an instance from a string
        static const LengthUnit& fromString(const std::string& s);   

    private:
        constexpr LengthUnit(const int& ft, const std::string_view& nm, const std::string_view& pnm, const std::string_view& ab) : Unit(ft, nm, pnm, ab) { }

};

struct LengthUnit::Instances : public Unit::Instances {
    static inline constexpr const LengthUnit Foot{1, "foot"sv, "feet"sv, "ft"sv};
    static inline constexpr const LengthUnit Mile{5280, "mile"sv, "miles"sv, "mi"sv};
};

using LengthUnits = LengthUnit::Instances;

} // end namespace DnD

#endif