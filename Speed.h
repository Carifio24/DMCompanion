#ifndef SPEED_H
#define SPEED_H

#include "Distance.h"
#include "SpeedType.h"

namespace DnD {

class Speed {

    public:

        // Constructor
        Speed(const Distance& dist, const SpeedType& type) : _dist(dist), _type(type) {}

        // Get member values
        Distance distance_per_round() const noexcept { return _dist; }
        const SpeedType& type() const noexcept { return _type; }

        // Compare two speeds
        bool operator<(const Speed& other) const { return _dist < other._dist; }
        bool operator=(const Speed& other) const { return _dist == other._dist; }


    private:

        // Member values
        // As speeds are always given as distance / round, a Speed consists of a distance and a speed type
        const Distance _dist;
        const SpeedType& _type;
};

} // end namespace DnD



#endif