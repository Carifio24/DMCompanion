#ifndef DURATION_TYPE_H
#define DURATION_TYPE_H

#include "named_enum.hpp"

namespace DnD {

class DurationTypeImpl : public NamedEnumImpl<DurationTypeImpl> {

    public:
        // The class instances
        struct Instances;

    private:
        // Constructor
        constexpr DurationTypeImpl(std::string_view name) : NamedEnumImpl<DurationTypeImpl>(name) {}

};

struct DurationTypeImpl::Instances {
    static inline constexpr const DurationTypeImpl Special{"Special"};
    static inline constexpr const DurationTypeImpl Instantaneous{"Instantaneous"};
    static inline constexpr const DurationTypeImpl Spanning{"Spanning"};
    static inline constexpr const DurationTypeImpl UntilDispelled{"Until dispelled"};
    static inline constexpr const DurationTypeImpl* const instances[] = { &Special, &Instantaneous, &Spanning, &UntilDispelled };
};

using DurationTypes = DurationTypeImpl::Instances;

class DurationType : public NamedEnum<DurationTypeImpl,DurationType> {

    public:
        DurationType(const DurationTypeImpl& dti) : NamedEnum<DurationTypeImpl,DurationType>(dti) {}

};


} // end namespace DnD


#endif