#ifndef TIME_UNIT_H
#define TIME_UNIT_H

#include "named_enum.hpp"

#include <vector>

namespace DnD {

class TimeUnitImpl : public NamedEnumImpl<TimeUnitImpl> {

    public:

        // The class instances
        struct Instances;

        // Get member values
        inline constexpr int value() const noexcept { return _value; }
        inline constexpr int in_seconds() const noexcept { return _value; }
        inline constexpr std::string_view plural_name() const noexcept { return _pl_name; }
        inline constexpr std::string_view abbreviation() const noexcept { return _abbr; }

        static const TimeUnitImpl& from_string(const std::string& s);

    private:
       constexpr TimeUnitImpl(int t, std::string_view name, std::string_view pl_name, std::string_view abbr) : NamedEnumImpl<TimeUnitImpl>(name), _value(t), _pl_name(pl_name), _abbr(abbr) {}

        const int _value;
        const std::string_view _pl_name;
        const std::string_view _abbr;
};

struct TimeUnitImpl::Instances {
    static inline constexpr const TimeUnitImpl Second{1, "second"sv, "seconds"sv, "s"sv};
    static inline constexpr const TimeUnitImpl Round{6, "round"sv, "rounds"sv, "rd"sv};
    static inline constexpr const TimeUnitImpl Minute{60, "minute"sv, "minutes"sv, "min"sv};
    static inline constexpr const TimeUnitImpl Hour{60*60, "hour"sv, "hours"sv, "hr"sv};
    static inline constexpr const TimeUnitImpl Day{24*60*60, "day"sv, "days"sv, "dy"sv};
    static inline constexpr const TimeUnitImpl Year{365*24*60*60, "year"sv, "years"sv, "yr"sv};
    static inline constexpr const TimeUnitImpl* const instances[] = { &Second, &Round, &Minute, &Hour, &Day, &Year};
};

using TimeUnits = TimeUnitImpl::Instances;


class TimeUnit : public NamedEnum<TimeUnitImpl,TimeUnit> {

    public:

        TimeUnit(const TimeUnitImpl& tui) : NamedEnum<TimeUnitImpl,TimeUnit>(tui) {}

        inline int value() const noexcept { return _impl.get().value(); }
        inline int in_seconds() const noexcept { return _impl.get().in_seconds(); }
        inline std::string_view plural_name() const noexcept { return _impl.get().plural_name(); }
        inline std::string_view abbreviation() const noexcept { return _impl.get().abbreviation(); }

        static TimeUnit from_string(const std::string& s) { return TimeUnit(TimeUnitImpl::from_string(s)); }

};

} // end namespace DnD

#endif