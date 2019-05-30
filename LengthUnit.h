#ifndef LENGTH_UNIT_H
#define LENGTH_UNIT_H

#include "Unit.h"

class LengthUnit : Unit {

    public:
        // The class instances
        struct Instances;     

    private:
        constexpr LengthUnit(const int& ft, const char* nm, const char* pnm, const char* ab) : Unit(ft, nm, pnm, ab) { }

};

struct LengthUnit::Instances {
    static inline constexpr const LengthUnit Foot{1, "foot", "feet", "ft"};
    static inline constexpr const LengthUnit Mile{5280, "mile", "miles", "mi"};
};

using LengthUnits = LengthUnit::Instances;

#endif