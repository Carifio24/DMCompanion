#ifndef DURATION_TYPE_H
#define DURATION_TYPE_H

#include "named_enum.hpp"

namespace DnD {

class DurationType : public NamedEnum<DurationType> {

    public:
        // The class instances
        struct Instances;

    private:
        // Constructor
        constexpr DurationType(const std::string_view& name) : NamedEnum<DurationType>(name) {}

};

struct DurationType::Instances {
    static inline constexpr const DurationType Special{"Special"};
    static inline constexpr const DurationType Instantaneous{"Instantaneous"};
    static inline constexpr const DurationType Spanning{"Spanning"};
    static inline constexpr const DurationType UntilDispelled{"Until dispelled"};
    static inline constexpr const DurationType* const instances[] = { &Special, &Instantaneous, &Spanning, &UntilDispelled };
};

using DurationTypes = DurationType::Instances;

} // end namespace DnD


#endif