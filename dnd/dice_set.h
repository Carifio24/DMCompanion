#ifndef DICE_SET_H
#define DICE_SET_H

#include "enumerations.h"
#include <map>

namespace DnD {

class DiceSet {

    public:
        DiceSet(const std::map<Die,int>& dmap) : _dmap(dmap) {}
        DiceSet() : DiceSet(std::map<Die,int>()) {}

        int roll() const noexcept;
        std::map<Die,int> dice() const noexcept { return _dmap; }

        static DiceSet from_string(std::string s);

    private:
        std::map<Die,int> _dmap;

};

} // end namespace DnD

#endif