#ifndef ABILITY_H
#define ABILITY_H

#include "named_enum.hpp"

namespace DnD {

class Ability : public NamedEnum<Ability> {

    public:
        struct Instances;

    private:
        constexpr Ability(const std::string_view& name, const std::string_view& abbr) : NamedEnum<Ability>(name), _abbr(abbr) {}
        const std::string_view _abbr;

};

struct Ability::Instances {
    static inline constexpr const Ability Strength{"Strength"sv, "Str"sv};
    static inline constexpr const Ability Dexterity{"Dexterity"sv, "Dex"sv};
    static inline constexpr const Ability Constitution{"Constitution"sv, "Con"sv};
    static inline constexpr const Ability Intelligence{"Intelligence"sv, "Int"sv};
    static inline constexpr const Ability Wisdom{"Wisdom"sv, "Wis"sv};
    static inline constexpr const Ability Charisma{"Charisma"sv, "Cha"sv};
    static inline constexpr const Ability* const instances[] = { &Strength, &Dexterity, &Constitution, &Intelligence, &Wisdom, &Charisma };
};

using Abilities = Ability::Instances;


} // end namespace DnD

#endif