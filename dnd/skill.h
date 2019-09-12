#ifndef SKILL_H
#define SKILL_H

#include "named_enum.hpp"
#include "ability.h"

namespace DnD {

class SkillImpl : public NamedEnumImpl<SkillImpl> {

    public:
        struct Instances;
        inline const AbilityImpl& ability() const noexcept { return _abl; }

    private:
        constexpr SkillImpl(const std::string_view& name, const AbilityImpl& abl) : NamedEnumImpl<SkillImpl>(name), _abl(abl) {}
        const AbilityImpl& _abl;
};

struct SkillImpl::Instances {
    static inline constexpr const SkillImpl Acrobatics{"Acrobatics"sv, Abilities::Dexterity};
    static inline constexpr const SkillImpl AnimalHandling{"Animal Handling"sv, Abilities::Wisdom};
    static inline constexpr const SkillImpl Arcana{"Arcana"sv, Abilities::Intelligence};
    static inline constexpr const SkillImpl Athletics{"Athletics"sv, Abilities::Strength};
    static inline constexpr const SkillImpl Deception{"Deception"sv, Abilities::Charisma};
    static inline constexpr const SkillImpl History{"History"sv, Abilities::Intelligence};
    static inline constexpr const SkillImpl Insight{"Insight"sv, Abilities::Wisdom};
    static inline constexpr const SkillImpl Intimidation{"Intimidation"sv, Abilities::Charisma};
    static inline constexpr const SkillImpl Investigation{"Investigation"sv, Abilities::Intelligence};
    static inline constexpr const SkillImpl Medicine{"Medicine"sv, Abilities::Wisdom};
    static inline constexpr const SkillImpl Nature{"Nature"sv, Abilities::Intelligence};
    static inline constexpr const SkillImpl Perception{"Perception"sv, Abilities::Wisdom};
    static inline constexpr const SkillImpl Performance{"Performance"sv, Abilities::Charisma};
    static inline constexpr const SkillImpl Persuasion{"Persuasion"sv, Abilities::Charisma};
    static inline constexpr const SkillImpl Religion{"Religion"sv, Abilities::Intelligence};
    static inline constexpr const SkillImpl SleightOfHand{"Sleight of Hand"sv, Abilities::Dexterity};
    static inline constexpr const SkillImpl Stealth{"Stealth"sv, Abilities::Dexterity};
    static inline constexpr const SkillImpl Survival{"Survival"sv, Abilities::Wisdom};
    static inline constexpr const SkillImpl* const instances [] = {
        &Acrobatics, &AnimalHandling, &Arcana, &Athletics, &Deception, &History, &Insight,
        &Intimidation, &Investigation, &Medicine, &Nature, &Perception, &Performance,
        &Persuasion, &Religion, &SleightOfHand, &Stealth, &Survival
    };
};

using Skills = SkillImpl::Instances;

class Skill : public NamedEnum<SkillImpl,Skill> {

    public:
        Skill(const SkillImpl& si) : NamedEnum<SkillImpl,Skill>(si) {}
        
        inline Ability ability() const noexcept { return Ability(_impl.get().ability()); }

};

}; // end namespace DnD

#endif