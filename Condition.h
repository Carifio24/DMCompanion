#ifndef CONDITION_H
#define CONDITION_H

#include "NamedEnum.h"

namespace DnD {

class Condition : public NamedEnum<Condition> {

    public:
        // The class instances
        struct Instances;

    private:
        constexpr Condition(const std::string_view& name) : NamedEnum<Condition>(name) {}

};

struct Condition::Instances {
    static inline constexpr const Condition Blinded{"Blinded"};
    static inline constexpr const Condition Charmed{"Charmed"};
    static inline constexpr const Condition Deafened{"Deafened"};
    static inline constexpr const Condition Exhaustion{"Exhaustion"};
    static inline constexpr const Condition Fatigued{"Fatigued"};
    static inline constexpr const Condition Frightened{"Frightened"};
    static inline constexpr const Condition Grappled{"Grappled"};
    static inline constexpr const Condition Incapacitated{"Incapacitated"};
    static inline constexpr const Condition Invisible{"Invisible"};
    static inline constexpr const Condition Paralyzed{"Paralyzed"};
    static inline constexpr const Condition Petrified{"Petrified"};
    static inline constexpr const Condition Poisoned{"Poisoned"};
    static inline constexpr const Condition Prone{"Prone"};
    static inline constexpr const Condition Restrained{"Restrained"};
    static inline constexpr const Condition Stunned{"Stunned"};
    static inline constexpr const Condition Unconscious{"Unconscious"};
    static inline constexpr const Condition* const instances[] = { &Blinded, &Charmed, &Deafened, &Exhaustion, &Fatigued, &Frightened, &Grappled, &Incapacitated, &Invisible, &Paralyzed, &Petrified, &Poisoned, &Prone, &Restrained, &Stunned, &Unconscious };
};

};

#endif