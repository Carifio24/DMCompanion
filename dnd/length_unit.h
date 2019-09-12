#ifndef LENGTH_UNIT_H
#define LENGTH_UNIT_H

#include "named_enum.hpp"

#include <vector>

namespace DnD {

class LengthUnitImpl : public NamedEnumImpl<LengthUnitImpl> {

    public:

        // Instances
        struct Instances;

        // Get member values
        inline constexpr int value() const noexcept { return _value; }
        inline constexpr int in_feet() const noexcept { return _value; }
        inline constexpr std::string_view plural_name() const noexcept { return _pl_name; }
        inline constexpr std::string_view abbreviation() const noexcept { return _abbr; }

        static const LengthUnitImpl& from_string(const std::string& s);

    private:
        constexpr LengthUnitImpl(const int& ft, const std::string_view& name, const std::string_view& pl_name, const std::string_view& abbr) : NamedEnumImpl<LengthUnitImpl>(name), _value(ft), _pl_name(pl_name), _abbr(abbr) {}
        const int _value;
        const std::string_view _pl_name;
        const std::string_view _abbr;
};

struct LengthUnitImpl::Instances {
    static inline constexpr const LengthUnitImpl Foot{1, "foot"sv, "feet"sv, "ft"sv};
    static inline constexpr const LengthUnitImpl Mile{5280, "mile"sv, "miles"sv, "mi"sv};
    static inline constexpr const LengthUnitImpl* const instances[] = { &Foot, & Mile };
};

using LengthUnits = LengthUnitImpl::Instances;

class LengthUnit : public NamedEnum<LengthUnitImpl,LengthUnit> {

    public:

        LengthUnit(const LengthUnitImpl& lui) : NamedEnum<LengthUnitImpl,LengthUnit>(lui) {}

        inline int value() const noexcept { return _impl.get().value(); }
        inline int in_feet() const noexcept { return _impl.get().in_feet(); }
        inline std::string_view plural_name() const noexcept { return _impl.get().plural_name(); }
        inline std::string_view abbreviation() const noexcept { return _impl.get().abbreviation(); }

        static LengthUnit from_string(const std::string& s) { return LengthUnit(LengthUnitImpl::from_string(s)); }

};

} // end namespace DnD

#endif