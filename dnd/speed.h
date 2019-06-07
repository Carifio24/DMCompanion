#ifndef SPEED_H
#define SPEED_H

#include "distance.h"
#include "speed_type.h"

#include <functional>

namespace DnD {

class Speed {

    public:

        // Constructor
        Speed(const SpeedType& type, const Distance& dist) : _type(type), _dist(dist) {}
        Speed(const Distance& dist) : Speed(SpeedTypes::Walk, dist) {}
        Speed() : Speed(SpeedTypes::Walk, Distance()) {}

        // Get member values
        Distance distance_per_round() const noexcept { return _dist; }
        const SpeedType& type() const noexcept { return _type.get(); }

        // Compare two speeds
        bool operator<(const Speed& other) const { return _dist < other._dist; }
        bool operator==(const Speed& other) const { return (_dist == other._dist) && (_type.get() == other._type.get()); }


    private:

        // Member values
        // As speeds are always given as distance / round, a Speed consists of a distance and a speed type
        Distance _dist;
        std::reference_wrapper<const SpeedType> _type;
};

} // end namespace DnD



#endif