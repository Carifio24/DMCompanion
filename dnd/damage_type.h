#ifndef DAMAGE_TYPE_H
#define DAMAGE_TYPE_H

#include "named_enum.hpp"

namespace DnD {

class DamageTypeImpl : public NamedEnumImpl<DamageTypeImpl> {

    public:
        struct Instances;

        inline constexpr std::string_view example() { return _example; }
    
    private:
        constexpr DamageTypeImpl(std::string_view name, std::string_view example) : NamedEnumImpl<DamageTypeImpl>(name), _example(example) {}

        const std::string_view _example;
};

struct DamageTypeImpl::Instances {
    static inline constexpr const DamageTypeImpl Damage{"Damage"sv, ""sv};
    static inline constexpr const DamageTypeImpl Acid{"Acid"sv, "The corrosive spray of a black dragon's breath and the dissolving enzymes secreted by a black pudding deal acid damage."sv};
    static inline constexpr const DamageTypeImpl Bludgeoning{"Bludgeoning"sv, "Blunt force attacks - hammers, falling, constriction, and the like - deal bludgeoning damage."sv};
    static inline constexpr const DamageTypeImpl Cold{"Cold"sv, "The infernal chill radiating from an ice devil's spear and the frigid blast of a white dragon's breath deal cold damage."sv};
    static inline constexpr const DamageTypeImpl Fire{"Fire"sv, "Red dragons breathe fire, and many spells conjure flames to deal fire damage."sv};
    static inline constexpr const DamageTypeImpl Force{"Force"sv, "Force is pure magical energy focused into a damaging form. Most effects that deal force damage are spells, including magic missile and spiritual weapon."sv};
    static inline constexpr const DamageTypeImpl Lightning{"Lightning"sv, "A lightning bolt spell and a blue dragon's breath deal lightning damage."sv};
    static inline constexpr const DamageTypeImpl Necrotic{"Necrotic"sv, "Necrotic damage, dealt by certain undead and a spell such as chill touch, withers matter and even the soul."sv};
    static inline constexpr const DamageTypeImpl Piercing{"Piercing"sv, "Puncturing and impaling attacks, including spears and monsters' bites, deal piercing damage."sv};
    static inline constexpr const DamageTypeImpl Poison{"Poison"sv, "Venomous stings and the toxic gas of a green dragon's breath deal poison damage."sv};
    static inline constexpr const DamageTypeImpl Psychic{"Psychic"sv, "Mental abilities such as a mind flayer's psionic blast deal psychic damage."sv};
    static inline constexpr const DamageTypeImpl Radiant{"Radiant"sv, "Radiant damage, dealt by a cleric's flame strike spell or an angel's smiting weapon, sears the flesh like fire and overloads the spirit with power."sv};
    static inline constexpr const DamageTypeImpl Slashing{"Slashing"sv, "Swords, axes, and monsters' claws deal slashing damage."sv};
    static inline constexpr const DamageTypeImpl Thunder{"Thunder"sv, "A concussive burst of sound, such as the effect of the thunderwave spell, deals thunder damage."sv};
    static inline constexpr const DamageTypeImpl* const instances[] = { &Damage, &Acid, &Bludgeoning, &Cold, &Fire, &Force, &Lightning, &Necrotic, &Piercing, &Poison, &Psychic, &Radiant, &Slashing, &Thunder };
};

using DamageTypes = DamageTypeImpl::Instances;

class DamageType : public NamedEnum<DamageTypeImpl,DamageType> {

    public:
        DamageType(const DamageTypeImpl& dti) : NamedEnum<DamageTypeImpl,DamageType>(dti) {}

};

} // end namespace DnD

#endif