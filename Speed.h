#ifndef SPEED_H
#define SPEED_h

#include "Distance.h"

namespace DnD {

class Speed {

    public:

        // Constructor
        Speed(const Distance& dist, const SpeedType& type) : _dist(dist), _type(type) {}

        // Get member values
        Distance distance_per_round() const noexcept { return _dist; }
        SpeedType& type() const noexcept { return _type; }

    private:

        // Member values
        // As speeds are always given as distance / round, a Speed consists of a distance and a speed type
        Distance _dist;
        SpeedType& _type;
};

} // end namespace DnD



#endif