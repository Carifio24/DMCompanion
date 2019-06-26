#ifndef SKILL_H
#define SKILL_H

#include "named_enum.hpp"
#include "ability.h"

namespace DnD {

class Skill : public NamedEnum<Skill> {

    public:
        struct Instances;
        inline constexpr const Ability& ability() const noexcept { return _abl; }

    private:
        constexpr Skill(const std::string_view& name, const Ability& abl) : NamedEnum<Skill>(name), _abl(abl) {}
        const Ability& _abl;
};

struct Skill::Instances {
    static inline constexpr const Skill Acrobatics{"Acrobatics"sv, Abilities::Dexterity};
    static inline constexpr const Skill AnimalHandling{"Animal Handling"sv, Abilities::Wisdom};
    static inline constexpr const Skill Arcana{"Arcana"sv, Abilities::Intelligence};
    static inline constexpr const Skill Athletics{"Athletics"sv, Abilities::Strength};
    static inline constexpr const Skill Deception{"Deception"sv, Abilities::Charisma};
    static inline constexpr const Skill History{"History"sv, Abilities::Intelligence};
    static inline constexpr const Skill Insight{"Insight"sv, Abilities::Wisdom};
    static inline constexpr const Skill Intimidation{"Intimidation"sv, Abilities::Charisma};
    static inline constexpr const Skill Investigation{"Investigation"sv, Abilities::Intelligence};
    static inline constexpr const Skill Medicine{"Medicine"sv, Abilities::Wisdom};
    static inline constexpr const Skill Nature{"Nature"sv, Abilities::Intelligence};
    static inline constexpr const Skill Perception{"Perception"sv, Abilities::Wisdom};
    static inline constexpr const Skill Performance{"Performance"sv, Abilities::Charisma};
    static inline constexpr const Skill Persuasion{"Persuasion"sv, Abilities::Charisma};
    static inline constexpr const Skill Religion{"Religion"sv, Abilities::Intelligence};
    static inline constexpr const Skill SleightOfHand{"Sleight of Hand"sv, Abilities::Dexterity};
    static inline constexpr const Skill Stealth{"Stealth"sv, Abilities::Dexterity};
    static inline constexpr const Skill Survival{"Survival"sv, Abilities::Wisdom};
    static inline constexpr const Skill* const instances [] = {
        &Acrobatics, &AnimalHandling, &Arcana, &Athletics, &Deception, &History, &Insight,
        &Intimidation, &Investigation, &Medicine, &Nature, &Perception, &Performance,
        &Persuasion, &Religion, &SleightOfHand, &Stealth, &Survival
    };
};

using Skills = Skill::Instances;

}; // end namespace DnD

#endif