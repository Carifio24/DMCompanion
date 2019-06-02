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
        SpeedType type() const noexcept { return _type; }

        static Speed fromString(const std::string& s);

    private:

        // Member values
        Distance _dist;
        SpeedType _type;
};

} // end namespace DnD



#endif