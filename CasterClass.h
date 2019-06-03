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

struct Casterclass::Instances {
    static inline constexpr const CasterClass Bard{"Bard", "Brd"};
    static inline constexpr const CasterClass Cleric{"Cleric", "Clr"};
    static inline constexpr const Casterclass Druid{"Druid", "Drd"};
    static inline constexpr const CasterClass Paladin{"Paladin", "Pal"};
    static inline constexpr const CasterClass Ranger{"Ranger", "Rgr"};
    static inline constexpr const CasterClass Sorcerer{"Sorcerer", "Src"};
    static inline constexpr const CasterClass Warlock{"Warlock", "Wlk"};
    static inline constexpr const CasterClass Wizard{"Wizard", "Wiz"};
    static inline constexpr const CasterClass* const instances = { &Bard, &Cleric, &Druid, &Paladin, &Ranger, &Sorcerer, &Warlock, &Wizard };
};

} // end namespace DnD

#endif