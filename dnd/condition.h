#ifndef CONDITION_H
#define CONDITION_H

#include "named_enum.hpp"

namespace DnD {

class ConditionImpl : public NamedEnumImpl<ConditionImpl> {

    public:
        // The class instances
        struct Instances;

    private:
        constexpr ConditionImpl(const std::string_view& name) : NamedEnumImpl<ConditionImpl>(name) {}

};

struct ConditionImpl::Instances {
    static inline constexpr const ConditionImpl Blinded{"Blinded"};
    static inline constexpr const ConditionImpl Charmed{"Charmed"};
    static inline constexpr const ConditionImpl Deafened{"Deafened"};
    static inline constexpr const ConditionImpl Exhaustion{"Exhaustion"};
    static inline constexpr const ConditionImpl Fatigued{"Fatigued"};
    static inline constexpr const ConditionImpl Frightened{"Frightened"};
    static inline constexpr const ConditionImpl Grappled{"Grappled"};
    static inline constexpr const ConditionImpl Incapacitated{"Incapacitated"};
    static inline constexpr const ConditionImpl Invisible{"Invisible"};
    static inline constexpr const ConditionImpl Paralyzed{"Paralyzed"};
    static inline constexpr const ConditionImpl Petrified{"Petrified"};
    static inline constexpr const ConditionImpl Poisoned{"Poisoned"};
    static inline constexpr const ConditionImpl Prone{"Prone"};
    static inline constexpr const ConditionImpl Restrained{"Restrained"};
    static inline constexpr const ConditionImpl Stunned{"Stunned"};
    static inline constexpr const ConditionImpl Unconscious{"Unconscious"};
    static inline constexpr const ConditionImpl* const instances[] = { &Blinded, &Charmed, &Deafened, &Exhaustion, &Fatigued, &Frightened, &Grappled, &Incapacitated, &Invisible, &Paralyzed, &Petrified, &Poisoned, &Prone, &Restrained, &Stunned, &Unconscious };
};

using Conditions = ConditionImpl::Instances;

class Condition : public NamedEnum<ConditionImpl,Condition> {

    public:
        Condition(const ConditionImpl& ci) : NamedEnum<ConditionImpl,Condition>(ci) {}

};

};

#endif