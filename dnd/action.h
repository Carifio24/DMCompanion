#ifndef ACTION_H
#define ACTION_H

#include "enumerations.h"
#include "dice_set.h"

namespace DnD {

class Action {

    public:

        // Constructor
        Action(const std::string& name, const std::string& desc, const int atk_bonus, const DiceSet& dset, const int dmg_bonus) :
            _name(name), _desc(desc), _atk_bonus(atk_bonus), _dset(dset), _dmg_bonus(dmg_bonus) {}

        Action() : Action("", "", 0, DiceSet(), 0) {}

        // Get member values
        std::string name() const noexcept { _name; }
        std::string description() const noexcept { _desc; }
        int attack_bonus() const noexcept { return _atk_bonus; }
        DiceSet dice() const noexcept { return _dset; }
        int damage_bonus() const noexcept { return _dmg_bonus; }
        
    private:
        // Member values
        std::string _name;
        std::string _desc;
        int _atk_bonus;
        DiceSet _dset;
        int _dmg_bonus;

};

} // end namespace DnD

#endif // ACTION_H
