#ifndef SENSE_H
#define SENSE_H

#include "SenseType.h"

namespace DnD {

class Sense {

    public:

        Sense(const int& dist, const SenseType& type) : _dist(dist), _type(type) {}

        int distance() const noexcept { return _dist; }
        const SenseType& type() const noexcept { return _type; }
    
    private:
        const SenseType& _type;
        const int _dist;
};

} // end namespace DnD

#endif