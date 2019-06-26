#ifndef DAMAGE_TYPE_H
#define DAMAGE_TYPE_H

#include "named_enum.hpp"

namespace DnD {

class DamageType : public NamedEnum<DamageType> {

    public:
        struct Instances;
    
    private:
        constexpr DamageType(const std::string_view& name) : NamedEnum<DamageType>(name) {}
};

struct DamageType::Instances {
    static inline constexpr const DamageType Damage{"Damage"sv};
    static inline constexpr const DamageType Acid{"Acid"sv};
    static inline constexpr const DamageType Bludgeoning{"Bludgeoning"sv};
    static inline constexpr const DamageType Cold{"Cold"sv};
    static inline constexpr const DamageType Fire{"Fire"sv};
    static inline constexpr const DamageType Force{"Force"sv};
    static inline constexpr const DamageType Lightning{"Lightning"sv};
    static inline constexpr const DamageType Necrotic{"Necrotic"sv};
    static inline constexpr const DamageType Piercing{"Piercing"sv};
    static inline constexpr const DamageType Poison{"Poison"sv};
    static inline constexpr const DamageType Psychic{"Psychic"sv};
    static inline constexpr const DamageType Radiant{"Radiant"sv};
    static inline constexpr const DamageType Slashing{"Slashing"sv};
    static inline constexpr const DamageType Thunder{"Thunder"sv};
    static inline constexpr const DamageType* const instances[] = { &Damage, &Acid, &Bludgeoning, &Cold, &Fire, &Force, &Lightning, &Necrotic, &Piercing, &Poison, &Psychic, &Radiant, &Slashing, &Thunder };
};

using DamageTypes = DamageType::Instances;

} // end namespace DnD

#endif