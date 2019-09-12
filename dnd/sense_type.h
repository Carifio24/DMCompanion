#ifndef SENSE_TYPE_H
#define SENSE_TYPE_H

#include "named_enum.hpp"

namespace DnD {

class SenseTypeImpl : public NamedEnumImpl<SenseTypeImpl> {

    public:
        struct Instances;

        inline constexpr std::string_view description() const noexcept { return _description; }

    private:
        constexpr SenseTypeImpl(std::string_view name, std::string_view description) : NamedEnumImpl<SenseTypeImpl>(name), _description(description) {}

        const std::string_view _description;
};

struct SenseTypeImpl::Instances {
    static inline constexpr const SenseTypeImpl Blindsight{"Blindsight"sv, "A creature with blindsight can perceive its surroundings without relying on sight, within a specific radius. Creatures without eyes, such as oozes, and creatures with echolocation or heightened senses, such as bats and true dragons, have this sense."sv};
    static inline constexpr const SenseTypeImpl Darkvision{"Darkvision"sv, "Many creatures in the worlds of D&D, especially those that dwell underground, have darkvision. Within a specified range, a creature with darkvision can see in darkness as if the darkness were dim light, so areas of darkness are only lightly obscured as far as that creature is concerned. However, the creature can't discern color in darkness, only shades of gray."sv};
    static inline constexpr const SenseTypeImpl Tremorsense{"Tremorsense"sv, "A creature with tremorsense is sensitive to vibrations in the ground and can automatically pinpoint the location of anything that is in contact with the ground and within range. If no straight path exists through the ground from the creature to those that it’s sensing, then the range defines the maximum distance of the shortest indirect path. It must itself be in contact with the ground, and the creatures must be moving. As long as the other creatures are taking physical actions, including casting spells with somatic components, they’re considered moving; they don’t have to move from place to place for a creature with tremorsense to detect them. Aquatic creatures with tremorsense can also sense the location of creatures moving through water. The ability’s range is specified in the creature’s descriptive text."sv};
    static inline constexpr const SenseTypeImpl Truesight{"Truesight"sv, "A creature with truesight can, out to a specific range, see in normal and magical darkness, see invisible creatures and objects, automatically detect visual illusions and succeed on saving throws against them, and perceives the original form of a shapechanger or a creature that is transformed by magic. Furthermore, the creature can see into the Ethereal Plane."sv};
    static inline constexpr const SenseTypeImpl* const instances[] = { &Blindsight, &Darkvision, &Tremorsense, &Truesight };
};

using SenseTypes = SenseTypeImpl::Instances;

class SenseType : public NamedEnum<SenseTypeImpl, SenseType> {

    public:
        SenseType(const SenseTypeImpl& sti) : NamedEnum<SenseTypeImpl,SenseType>(sti) {}

        inline std::string_view description() const noexcept { return _impl.get().description(); }

};

} // end namespace DnD

#endif