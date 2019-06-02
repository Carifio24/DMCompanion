#ifndef SOURCEBOOK_H
#define SOURCEBOOK_H

#include "NamedEnum.h"

namespace DnD {

class Sourcebook : public NamedEnum<Sourcebook> {

    public:

        // The class instances
        struct Instances;

        inline constexpr std::string_view abbreviation() const noexcept { return _abbr; }

        inline static const Sourcebook& fromAbbreviation(std::string s) { 
            const std::function<void(std::string& s)> make_upper = [](std::string& s) { std::transform(s.begin(), s.end(), s.begin(), ::toupper); };
            return fromMember(s, &Sourcebook::_abbr, make_upper);
        }

    private:
        constexpr Sourcebook(const std::string_view& name, const std::string_view& abbr) : NamedEnum<Sourcebook>(name), _abbr(abbr) {}
        const std::string_view _abbr;
};

struct Sourcebook::Instances {
    static inline constexpr const Sourcebook PlayersHandbook{"Player's Handbook"sv, "PHB"sv};
    static inline constexpr const Sourcebook XanatharsGTE{"Xanathar's Guide to Everything"sv, "XGE"sv};
    static inline constexpr const Sourcebook SwordCoastAG{"Sword Coast Adventurer's Guide"sv, "SCAG"sv};
    static inline constexpr const Sourcebook* instances[] = { &PlayersHandbook, &XanatharsGTE, &SwordCoastAG };
};

using Sourcebooks = Sourcebook::Instances;

} // end namespace DnD

#endif