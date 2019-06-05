#ifndef TIME_UNIT_H
#define TIME_UNIT_H

#include "named_enum.hpp"

#include <vector>

namespace DnD {

class TimeUnit : public NamedEnum<TimeUnit> {

    public:

        // The class instances
        struct Instances;

        // Get member values
        inline constexpr int value() const noexcept { return _value; }
        inline constexpr int in_seconds() const noexcept { return _value; }
        inline constexpr std::string_view plural_name() const noexcept { return _pl_name; }
        inline constexpr std::string_view abbreviation() const noexcept { return _abbr; }

    private:
       constexpr TimeUnit(const int& t, const std::string_view& name, const std::string_view& pl_name, const std::string_view& abbr) : NamedEnum<TimeUnit>(name), _value(t), _pl_name(pl_name), _abbr(abbr) {}

        const int _value;
        const std::string_view _pl_name;
        const std::string_view _abbr;
};

struct TimeUnit::Instances {
    static inline constexpr const TimeUnit Second{1, "second"sv, "seconds"sv, "s"sv};
    static inline constexpr const TimeUnit Round{6, "round"sv, "rounds"sv, "rd"sv};
    static inline constexpr const TimeUnit Minute{60, "minute"sv, "minutes"sv, "min"sv};
    static inline constexpr const TimeUnit Hour{60*60, "hour"sv, "hours"sv, "hr"sv};
    static inline constexpr const TimeUnit Day{24*60*60, "day"sv, "days"sv, "dy"sv};
    static inline constexpr const TimeUnit Year{365*24*60*60, "year"sv, "years"sv, "yr"sv};
    static inline constexpr const TimeUnit* const instances[] = { &Second, &Round, &Minute, &Hour, &Day, &Year};
};

using TimeUnits = TimeUnit::Instances;

} // end namespace DnD

#endif