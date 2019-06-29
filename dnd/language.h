#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "named_enum.hpp"

namespace DnD {

class Language :  public NamedEnum<Language> {

    public:
        struct Instances;
        inline constexpr bool common() const noexcept { return _common; }

    private:
        constexpr Language(const std::string_view& name, bool common) : NamedEnum<Language>(name), _common(common) {}
        bool _common;
};

struct Language::Instances {
    static inline constexpr const Language Common{"Common", true};
    static inline constexpr const Language Dwarvish{"Dwarvish", true};
    static inline constexpr const Language Elvish{"Elvish", true};
    static inline constexpr const Language Giant{"Giant", true};
    static inline constexpr const Language Gnomish{"Gnomish", true};
    static inline constexpr const Language Goblin{"Goblin", true};
    static inline constexpr const Language Halfling{"Halfling", true};
    static inline constexpr const Language Orc{"Orc", true};
    static inline constexpr const Language Abyssal{"Abyssal", false};
    static inline constexpr const Language Celestial{"Celestial", false};
    static inline constexpr const Language DeepSpeech{"Deep Speech", false};
    static inline constexpr const Language Draconic{"Draconic", false};
    static inline constexpr const Language Druidic{"Druidic", false};
    static inline constexpr const Language Infernal{"Infernal", false};
    static inline constexpr const Language Primordial{"Primordial", false};
    static inline constexpr const Language Sylvan{"Sylvan", false};
    static inline constexpr const Language Undercommon{"Undercommon", false};
    static inline constexpr const Language* const instances[] = {
        &Common, &Dwarvish, &Elvish, &Giant, &Gnomish, &Goblin, &Halfling, &Orc,
        &Abyssal, &Celestial, &DeepSpeech, &Draconic, &Druidic, &Infernal, &Primordial, &Sylvan, &Undercommon
    };
};

using Languages = Language::Instances;

} // end namespace DnD

#endif