#ifndef DISTANCE_TYPE_H
#define DISTANCE_TYPE_H

#include "named_enum.hpp"

namespace DnD {

class DistanceType : public NamedEnum<DistanceType> {

    public:
        // The class instances
        struct Instances;

    private:
        constexpr DistanceType(const std::string_view& name) : NamedEnum<DistanceType>(name) {}

};

struct DistanceType::Instances {
    static inline constexpr const DistanceType Special{"Special"};
    static inline constexpr const DistanceType Self{"Self"};
    static inline constexpr const DistanceType Touch{"Touch"};
    static inline constexpr const DistanceType Sight{"Sight"};
    static inline constexpr const DistanceType Distanced{"Distanced"};
    static inline constexpr const DistanceType Unlimited{"Unlimited"};
    static inline constexpr const DistanceType* const instances[] = { &Special, &Self, &Touch, &Sight, &Distanced, &Unlimited };
};

using DistanceTypes = DistanceType::Instances;

} // end namespace DnD

#endif