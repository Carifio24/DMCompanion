#ifndef SPEED_TYPE_H
#define SPEED_TYPE_H

#include "named_enum.hpp"

namespace DnD {

class SpeedTypeImpl : public NamedEnumImpl<SpeedTypeImpl> {

    public:

        // The class instances
        struct Instances;

    private:

        // Constructor
        constexpr SpeedTypeImpl(std::string_view name) : NamedEnumImpl<SpeedTypeImpl>(name) {}

};

struct SpeedTypeImpl::Instances {
    static inline constexpr const SpeedTypeImpl Walk{"walking"sv};
    static inline constexpr const SpeedTypeImpl Burrow{"burrow"sv};
    static inline constexpr const SpeedTypeImpl Climb{"climb"sv};
    static inline constexpr const SpeedTypeImpl Fly{"fly"sv};
    static inline constexpr const SpeedTypeImpl Swim{"swim"sv};
    static inline constexpr const SpeedTypeImpl Rolling{"rolling"sv};
    static inline constexpr const SpeedTypeImpl Downhill{"downhill"sv};
    static inline constexpr const SpeedTypeImpl* const instances[] = { &Walk, &Burrow, &Climb, &Fly, &Swim, &Rolling, &Downhill };
};

using SpeedTypes = SpeedTypeImpl::Instances;

class SpeedType : public NamedEnum<SpeedTypeImpl,SpeedType> {

    public:
        SpeedType(const SpeedTypeImpl& sti) : NamedEnum<SpeedTypeImpl,SpeedType>(sti) {}

};

} // end namespace DnD;

#endif