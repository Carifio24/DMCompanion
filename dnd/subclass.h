#ifndef SUBCLASS_H
#define SUBCLASS_H

#include "named_enum.hpp"

namespace DnD {

class Subclass : public NamedEnum<Subclass> {

    public:
        // The class instances
        struct Instances;

        inline constexpr std::string_view abbreviation() const noexcept { return _abbr; }

        static const Subclass& from_abbreviation(const std::string& s) {
            return from_member(s, &Subclass::abbreviation);
        }

    private:
        constexpr Subclass(const std::string_view& name, const std::string_view& abbr) : NamedEnum<Subclass>(name), _abbr(abbr) {}
        const std::string_view _abbr;
};

} // end namespace DnD

#endif