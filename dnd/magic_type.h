#ifndef MAGIC_TYPE_H
#define MAGIC_TYPE_H

#include "named_enum.hpp"

namespace DnD {

class MagicTypeImpl : public NamedEnumImpl<MagicTypeImpl> {

    public:
        struct Instances;

    private:
        constexpr MagicTypeImpl(std::string_view name) : NamedEnumImpl<MagicTypeImpl>(name) {}

};

struct MagicTypeImpl::Instances {
    static inline constexpr const MagicTypeImpl Any{"Any"};
    static inline constexpr const MagicTypeImpl Magical{"Magical"};
    static inline constexpr const MagicTypeImpl Nonmagical{"Nonmagical"};
    static inline constexpr const MagicTypeImpl* const instances[] = { &Any, &Magical, &Nonmagical };
};

using MagicTypes = MagicTypeImpl::Instances;

class MagicType : public NamedEnum<MagicTypeImpl,MagicType> {

    public:
        MagicType(const MagicTypeImpl& mti) : NamedEnum<MagicTypeImpl,MagicType>(mti) {}

};

} // end namespace DnD

#endif