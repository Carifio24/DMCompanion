#include "Unit.h"

class TimeUnit : Unit {

    public:

        // The class instances
        struct Instances;

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
};

using TimeUnits = TimeUnit::Instances;