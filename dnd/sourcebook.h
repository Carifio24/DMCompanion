#ifndef SOURCEBOOK_H
#define SOURCEBOOK_H

#include "named_enum.hpp"

namespace DnD {

class SourcebookImpl : public NamedEnumImpl<SourcebookImpl> {

    public:

        // The class instances
        struct Instances;

        inline constexpr std::string_view abbreviation() const noexcept { return _abbr; }

        static const SourcebookImpl& from_abbreviation(std::string s) { 
            const std::function<void(std::string& s)> make_upper = [](std::string& s) { std::transform(s.begin(), s.end(), s.begin(), ::toupper); };
            return from_member(s, &SourcebookImpl::abbreviation, make_upper);
        }

    private:
        constexpr SourcebookImpl(std::string_view name, std::string_view abbr) : NamedEnumImpl<SourcebookImpl>(name), _abbr(abbr) {}
        const std::string_view _abbr;
};

struct SourcebookImpl::Instances {
    static inline constexpr const SourcebookImpl PlayersHandbook{"Player's Handbook"sv, "PHB"sv};
    static inline constexpr const SourcebookImpl XanatharsGTE{"Xanathar's Guide to Everything"sv, "XGE"sv};
    static inline constexpr const SourcebookImpl SwordCoastAG{"Sword Coast Adventurer's Guide"sv, "SCAG"sv};
    static inline constexpr const SourcebookImpl* const instances[] = { &PlayersHandbook, &XanatharsGTE, &SwordCoastAG };
};

using Sourcebooks = SourcebookImpl::Instances;

class Sourcebook : public NamedEnum<SourcebookImpl,Sourcebook> {

    public:

        Sourcebook(const SourcebookImpl& sbi) : NamedEnum<SourcebookImpl,Sourcebook>(sbi) {}

        inline std::string_view abbreviation() const noexcept { return _impl.get().abbreviation(); }

        static Sourcebook from_abbreviation(std::string s) { return Sourcebook(SourcebookImpl::from_abbreviation(s)); }
};

} // end namespace DnD

#endif