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
        static const TimeUnit& fromString(const std::string& s);

    private:
        constexpr TimeUnit(const int& sec, const char* nm, const char* pnm, const char* ab) : Unit(sec, nm, pnm, ab) { }
};

struct TimeUnit::Instances {
    static inline constexpr const TimeUnit Second{1, "second"sv, "seconds"sv, "s"sv};
    static inline constexpr const TimeUnit Round{6, "round"sv, "rounds"sv, "rd"sv};
    static inline constexpr const TimeUnit Minute{60, "minute"sv, "minutes"sv, "min"sv};
    static inline constexpr const TimeUnit Hour{60*60, "hour"sv, "hours"sv, "hr"sv};
    static inline constexpr const TimeUnit Day{24*60*60, "day"sv, "days"sv, "dy"sv};
    static inline constexpr const TimeUnit Year{365*24*60*60, "year"sv, "years"sv, "yr"sv};
    static const std::vector<const TimeUnit*> instances;
};

using TimeUnits = TimeUnit::Instances;

} // end namespace DnD

#endif