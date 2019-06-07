#ifndef SENSE_TYPE_H
#define SENSE_TYPE_H

#include "named_enum.hpp"

namespace DnD {

class SenseType : public NamedEnum<SenseType> {

    public:
        struct Instances;

    private:
        constexpr SenseType(const std::string_view& name) : NamedEnum<SenseType>(name) {}
};

struct SenseType::Instances {
    static inline constexpr const SenseType Blindsight{"Blindsight"};
    static inline constexpr const SenseType Darkvision{"Darkvision"};
    static inline constexpr const SenseType Tremorsense{"Tremorsense"};
    static inline constexpr const SenseType Truesight{"Truesight"};
    static inline constexpr const SenseType* const instances[] = { &Blindsight, &Darkvision, &Tremorsense, &Truesight };
};

} // end namespace DnD

#endif