#ifndef MAGIC_TYPE_H
#define MAGIC_TYPE_H

#include "named_enum.hpp"

namespace DnD {

class MagicType : public NamedEnum<MagicType> {

    public:
        struct Instances;

    private:
        constexpr MagicType(const std::string_view& name) : NamedEnum<MagicType>(name) {}

};

struct MagicType::Instances {
    static inline constexpr const MagicType Any{"Any"};
    static inline constexpr const MagicType Magical{"Magical"};
    static inline constexpr const MagicType Nonmagical{"Nonmagical"};
    static inline constexpr const MagicType* const instances[] = { &Any, &Magical, &Nonmagical };
};

using MagicTypes = MagicType::Instances;

} // end namespace DnD

#endif