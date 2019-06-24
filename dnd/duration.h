#ifndef DURATION_H
#define DURATION_H

#include "time_unit.h"
#include "quantity.hpp"
#include "duration_type.h"

#include <vector>

namespace DnD {

class Duration : public Quantity<DurationType, TimeUnit> {

    public:

        // Constructors
        Duration(const DurationType& rt, const int& value, const TimeUnit& unit, const std::string& str="") : Quantity<DurationType, TimeUnit>(rt, value, unit, str) {}
        Duration() : Duration(DurationTypes::Instantaneous, 0, TimeUnits::Second) {}

        bool operator==(const Duration& other) const noexcept;

        // Methods
        int time_in_seconds() const noexcept { return base_value(); }
        std::string string() const;
        static Duration from_string(std::string s);

};

} // end namespace DnD


#endif