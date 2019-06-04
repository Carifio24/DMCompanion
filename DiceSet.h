#ifndef DICE_SET_H
#define DICE_SET_H

#include "Enumerations.h"
#include <map>

namespace DnD {

class DiceSet {

    public:
        int roll() const noexcept;
        std::map<Die,int> dice() const noexcept { return _dice; }

    private:
        std::map<Die,int> _dice;

};

} // end namespace DnD

#endif