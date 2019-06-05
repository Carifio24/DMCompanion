#ifndef LENGTH_UNIT_H
#define LENGTH_UNIT_H

#include "named_enum.hpp"

#include <vector>

namespace DnD {

class LengthUnit : public NamedEnum<LengthUnit> {

    public:

        // Instances
        struct Instances;

        // Get member values
        inline constexpr int value() const noexcept { return _value; }
        inline constexpr int in_feet() const noexcept { return _value; }
        inline constexpr std::string_view plural_name() const noexcept { return _pl_name; }
        inline constexpr std::string_view abbreviation() const noexcept { return _abbr; }

        static const LengthUnit& from_string(const std::string& s);

    private:
        constexpr LengthUnit(const int& ft, const std::string_view& name, const std::string_view& pl_name, const std::string_view& abbr) : NamedEnum<LengthUnit>(name), _value(ft), _pl_name(pl_name), _abbr(abbr) {}
        const int _value;
        const std::string_view _pl_name;
        const std::string_view _abbr;
};

struct LengthUnit::Instances {
    static inline constexpr const LengthUnit Foot{1, "foot"sv, "feet"sv, "ft"sv};
    static inline constexpr const LengthUnit Mile{5280, "mile"sv, "miles"sv, "mi"sv};
    static inline constexpr const LengthUnit* const instances[] = { &Foot, & Mile };
};

using LengthUnits = LengthUnit::Instances;

} // end namespace DnD

#endif