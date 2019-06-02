#ifndef DURATION_H
#define DURATION_H

#include "TimeUnit.h"
#include "Quantity.hpp"

#include <vector>

namespace DnD {

enum DurationType { Special=0, Instantaneous, Spanning, UntilDispelled };

class Duration : public Quantity<DurationType, TimeUnit> {

    public:

        // Constructors
        Duration(const DurationType& rt, const int& value, const TimeUnit& unit, const std::string& str="") : Quantity<DurationType, TimeUnit>(rt, value, unit, str) {}
        Duration() : Duration(Instantaneous, 0, TimeUnits::Second) {}

        // Methods
        int time_in_seconds() const { return base_value(); }
        std::string string() const;
        static Duration fromString(const std::string& s);

        // Constant vector of names
        static const std::vector<std::string> typeNames;

};

} // end namespace DnD


#endif