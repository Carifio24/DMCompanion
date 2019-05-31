#ifndef TIME_UNIT_H
#define TIME_UNIT_H

#include "Unit.h"

#include <vector>

namespace DnD {

class TimeUnit : public Unit {

    public:

        // The class instances
        struct Instances;

        // Get an instance from a string
        static const TimeUnit& fromSTring(const std::string& s);

    private:
        constexpr TimeUnit(const int& sec, const char* nm, const char* pnm, const char* ab) : Unit(sec, nm, pnm, ab) { }
};

struct TimeUnit::Instances {
    static constexpr const TimeUnit Second{1, "second", "seconds", "s"};
    static constexpr const TimeUnit Round{6, "round", "rounds", "rd"};
    static constexpr const TimeUnit Minute{60, "minute", "minutes", "min"};
    static constexpr const TimeUnit Hour{60*60, "hour", "hours", "hr"};
    static constexpr const TimeUnit Day{24*60*60, "day", "days", "dy"};
    static constexpr const TimeUnit Year{365*24*60*60, "year", "years", "yr"};
    static const std::vector<const TimeUnit*> instances;
};

using TimeUnits = TimeUnit::Instances;

} // end namespace DnD

#endif