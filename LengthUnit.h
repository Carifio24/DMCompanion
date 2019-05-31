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
        constexpr LengthUnit(const int& ft, const char* nm, const char* pnm, const char* ab) : Unit(ft, nm, pnm, ab) { }

};

struct LengthUnit::Instances {
    static inline constexpr const LengthUnit Foot{1, "foot", "feet", "ft"};
    static inline constexpr const LengthUnit Mile{5280, "mile", "miles", "mi"};
    static const std::vector<const LengthUnit*> instances;

};

using LengthUnits = LengthUnit::Instances;

} // end namespace DnD

#endif