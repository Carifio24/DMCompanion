#ifndef DISTANCE_TYPE_H
#define DISTANCE_TYPE_H

#include "named_enum.hpp"

namespace DnD {

class DistanceTypeImpl : public NamedEnumImpl<DistanceTypeImpl> {

    public:
        // The class instances
        struct Instances;

    private:
        constexpr DistanceTypeImpl(std::string_view name) : NamedEnumImpl<DistanceTypeImpl>(name) {}

};

struct DistanceTypeImpl::Instances {
    static inline constexpr const DistanceTypeImpl Special{"Special"sv};
    static inline constexpr const DistanceTypeImpl Self{"Self"sv};
    static inline constexpr const DistanceTypeImpl Touch{"Touch"sv};
    static inline constexpr const DistanceTypeImpl Sight{"Sight"sv};
    static inline constexpr const DistanceTypeImpl Distanced{"Distanced"sv};
    static inline constexpr const DistanceTypeImpl Unlimited{"Unlimited"sv};
    static inline constexpr const DistanceTypeImpl* const instances[] = { &Special, &Self, &Touch, &Sight, &Distanced, &Unlimited };
};

using DistanceTypes = DistanceTypeImpl::Instances;


class DistanceType : public NamedEnum<DistanceTypeImpl,DistanceType> {

    public:
        DistanceType(const DistanceTypeImpl& dti) : NamedEnum<DistanceTypeImpl,DistanceType>(dti) {}

};

} // end namespace DnD

#endif