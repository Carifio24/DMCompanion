#ifndef CASTER_CLASS_H
#define CASTER_CLASS_H

namespace DnD {

class CasterClassImpl : public NamedEnumImpl<CasterClassImpl> {

    public:
        // The class instances
        struct Instances;

        inline constexpr std::string_view abbreviation() const noexcept { return _abbr; }

        static const CasterClassImpl& from_abbreviation(const std::string& s) {
            return from_member(s, &CasterClassImpl::abbreviation);
        }

    private:
        constexpr CasterClassImpl(const std::string_view& name, const std::string_view& abbr) : NamedEnumImpl<CasterClassImpl>(name), _abbr(abbr) {}
        const std::string_view _abbr;
};

struct CasterClassImpl::Instances {
    static inline constexpr const CasterClassImpl Bard{"Bard"sv, "Brd"sv};
    static inline constexpr const CasterClassImpl Cleric{"Cleric"sv, "Clr"sv};
    static inline constexpr const CasterClassImpl Druid{"Druid"sv, "Drd"sv};
    static inline constexpr const CasterClassImpl Paladin{"Paladin"sv, "Pal"sv};
    static inline constexpr const CasterClassImpl Ranger{"Ranger"sv, "Rgr"sv};
    static inline constexpr const CasterClassImpl Sorcerer{"Sorcerer"sv, "Src"sv};
    static inline constexpr const CasterClassImpl Warlock{"Warlock"sv, "Wlk"sv};
    static inline constexpr const CasterClassImpl Wizard{"Wizard"sv, "Wiz"sv};
    static inline constexpr const CasterClassImpl* const instances[] = { &Bard, &Cleric, &Druid, &Paladin, &Ranger, &Sorcerer, &Warlock, &Wizard };
};

using CasterClasses = CasterClassImpl::Instances;

class CasterClass : public NamedEnum<CasterClassImpl,CasterClass> {

    public:

        CasterClass(const CasterClassImpl& cci) : NamedEnum<CasterClassImpl,CasterClass>(cci) {}

        inline std::string_view abbreviation() const noexcept { return _impl.get().abbreviation(); }

};

} // end namespace DnD

#endif