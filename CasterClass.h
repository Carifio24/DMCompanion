#ifndef CASTER_CLASS_H
#define CASTER_CLASS_H

namespace DnD {

class CasterClass : public NamedEnum<School> {

    public:
        // The class instances
        struct Instances;

        inline constexpr std::string_view abbreviation() const noexcept { return _abbr; }

        static const CasterClass& from_abbreviation(const std::string& s) {
            return from_member(s, &CasterClass::abbreviation);
        }

    private:
        constexpr CasterClass(const std::string_view& name, const std::string_view& abbr) : NamedEnum<School>(name), _abbr(abbr) {}
        const std::string_view _abbr;
};

struct CasterClass::Instances {
    static inline constexpr const CasterClass Bard{"Bard"sv, "Brd"sv};
    static inline constexpr const CasterClass Cleric{"Cleric"sv, "Clr"sv};
    static inline constexpr const CasterClass Druid{"Druid"sv, "Drd"sv};
    static inline constexpr const CasterClass Paladin{"Paladin"sv, "Pal"sv};
    static inline constexpr const CasterClass Ranger{"Ranger"sv, "Rgr"sv};
    static inline constexpr const CasterClass Sorcerer{"Sorcerer"sv, "Src"sv};
    static inline constexpr const CasterClass Warlock{"Warlock"sv, "Wlk"sv};
    static inline constexpr const CasterClass Wizard{"Wizard"sv, "Wiz"sv};
    static inline constexpr const CasterClass* const instances = { &Bard, &Cleric, &Druid, &Paladin, &Ranger, &Sorcerer, &Warlock, &Wizard };
};

using CasterClasses = CasterClass::Instances;

} // end namespace DnD

#endif