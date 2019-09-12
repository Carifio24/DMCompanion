#ifndef SENSE_H
#define SENSE_H

#include "sense_type.h"
#include "distance.h"

namespace DnD {

class Sense {

    public:

        Sense(const SenseType& type, const DnD::Distance& dist) : _type(type), _dist(dist) {}

        DnD::Distance distance() const noexcept { return _dist; }
        const SenseType& type() const noexcept { return _type; }
    
    private:
        SenseType _type;
        DnD::Distance _dist;
};

} // end namespace DnD

#endif