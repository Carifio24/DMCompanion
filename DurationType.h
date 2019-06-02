#ifndef DURATION_TYPE_H
#define DURATION_TYPE_H

#include "NamedEnum.h"

namespace DnD {

class DurationType : public NamedEnum<DurationType> {

    public:
        // The class instances
        struct Instances;

        // Get an instance from a string
        static const DurationType& fromString(const std::string& s);

    private:
        // Constructor
        constexpr DurationType(const int& secs, const std::string_view& name) : NamedEnum(secs, name);

};


} // end namespace DnD





#endif