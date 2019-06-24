#ifndef LEGENDARY_ACTION_H
#define LEGENDARY_ACTION_H

#include <string>

namespace DnD {

class LegendaryAction {

    public:

        // Constructor
        LegendaryAction(const std::string& name, const std::string& desc, const int atk_bonus) :
            _name(name), _desc(desc), _atk_bonus(atk_bonus) {}

        LegendaryAction() : LegendaryAction("", "", 0) {}

        // Get member values
        std::string name() const noexcept { _name; }
        std::string description() const noexcept { _desc; }
        int attack_bonus() const noexcept { return _atk_bonus; }
        
    private:
        // Member values
        std::string _name;
        std::string _desc;
        int _atk_bonus;

};

} // end namespace DnD

#endif // ACTION_H