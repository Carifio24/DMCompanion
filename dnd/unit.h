#ifndef UNIT_H
#define UNIT_H

#include "named_enum.hpp"

namespace DnD {

class UnitImpl : public NamedEnumImpl<UnitImpl> {

    public:

        // Get member values
        inline constexpr std::string_view plural_name() const noexcept { return _pl_name; }
        inline constexpr std::string_view abbreviation() const noexcept { return _abbr; }

    protected:

        constexpr UnitImpl(const int& value, const std::string_view& name, const std::string_view& pl_name, const std::string_view& abbr) : NamedEnumImpl<UnitImpl>(value, name), _pl_name(pl_name), _abbr(abbr) {}

        const std::string_view _pl_name;
        const std::string_view _abbr;
};

} // end namespace DnD

#endif