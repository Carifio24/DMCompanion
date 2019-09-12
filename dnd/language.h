#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "named_enum.hpp"

namespace DnD {

class LanguageImpl :  public NamedEnumImpl<LanguageImpl> {

    public:
        struct Instances;
        inline constexpr bool common() const noexcept { return _common; }

    private:
        constexpr LanguageImpl(const std::string_view& name, bool common) : NamedEnumImpl<LanguageImpl>(name), _common(common) {}
        bool _common;
};

struct LanguageImpl::Instances {
    static inline constexpr const LanguageImpl Common{"Common", true};
    static inline constexpr const LanguageImpl Dwarvish{"Dwarvish", true};
    static inline constexpr const LanguageImpl Elvish{"Elvish", true};
    static inline constexpr const LanguageImpl Giant{"Giant", true};
    static inline constexpr const LanguageImpl Gnomish{"Gnomish", true};
    static inline constexpr const LanguageImpl Goblin{"Goblin", true};
    static inline constexpr const LanguageImpl Halfling{"Halfling", true};
    static inline constexpr const LanguageImpl Orc{"Orc", true};
    static inline constexpr const LanguageImpl Abyssal{"Abyssal", false};
    static inline constexpr const LanguageImpl Celestial{"Celestial", false};
    static inline constexpr const LanguageImpl DeepSpeech{"Deep Speech", false};
    static inline constexpr const LanguageImpl Draconic{"Draconic", false};
    static inline constexpr const LanguageImpl Druidic{"Druidic", false};
    static inline constexpr const LanguageImpl Infernal{"Infernal", false};
    static inline constexpr const LanguageImpl Primordial{"Primordial", false};
    static inline constexpr const LanguageImpl Sylvan{"Sylvan", false};
    static inline constexpr const LanguageImpl Undercommon{"Undercommon", false};
    static inline constexpr const LanguageImpl* const instances[] = {
        &Common, &Dwarvish, &Elvish, &Giant, &Gnomish, &Goblin, &Halfling, &Orc,
        &Abyssal, &Celestial, &DeepSpeech, &Draconic, &Druidic, &Infernal, &Primordial, &Sylvan, &Undercommon
    };
};

using Languages = LanguageImpl::Instances;
using Language = NamedEnum<LanguageImpl,Language>;

} // end namespace DnD

#endif