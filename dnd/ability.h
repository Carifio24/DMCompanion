#ifndef ABILITY_H
#define ABILITY_H

#include "named_enum.hpp"

namespace DnD {

class AbilityImpl : public NamedEnumImpl<AbilityImpl> {

    public:
        struct Instances;

        inline constexpr std::string_view abbreviation() const noexcept { return _abbr; }

    private:
        constexpr AbilityImpl(const std::string_view& name, const std::string_view& abbr) : NamedEnumImpl<AbilityImpl>(name), _abbr(abbr) {}
        const std::string_view _abbr;

};

struct AbilityImpl::Instances {
    static inline constexpr const AbilityImpl Strength{"Strength"sv, "Str"sv};
    static inline constexpr const AbilityImpl Dexterity{"Dexterity"sv, "Dex"sv};
    static inline constexpr const AbilityImpl Constitution{"Constitution"sv, "Con"sv};
    static inline constexpr const AbilityImpl Intelligence{"Intelligence"sv, "Int"sv};
    static inline constexpr const AbilityImpl Wisdom{"Wisdom"sv, "Wis"sv};
    static inline constexpr const AbilityImpl Charisma{"Charisma"sv, "Cha"sv};
    static inline constexpr const AbilityImpl* const instances[] = { &Strength, &Dexterity, &Constitution, &Intelligence, &Wisdom, &Charisma };
};

using Abilities = AbilityImpl::Instances;

class Ability : public NamedEnum<AbilityImpl,Ability> {

    public:

        Ability(const AbilityImpl& ai) : NamedEnum<AbilityImpl,Ability>(ai) {}

        inline std::string_view abbreviation() { return _impl.get().abbreviation(); }

};


} // end namespace DnD

#endif