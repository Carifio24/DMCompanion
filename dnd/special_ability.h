#ifndef SPECIAL_ABILITY_H
#define SPECIAL_ABILITY_H

#include <string>

namespace DnD {

class SpecialAbility {

    public:
        // Constructors
        SpecialAbility(const std::string& nm, const std::string& dscr, int ab) : _name(nm), _desc(dscr), _atk_bonus(ab) {}

        // Default constructor
        SpecialAbility() : SpecialAbility("", "", 0) {}

        // Get member values
        std::string name() const noexcept { return _name; }
        std::string description() const noexcept { return _desc; }
        int attack_bonus() const noexcept { return _atk_bonus; }


    private:
        // Properties
        std::string _name;
        std::string _desc;
        int _atk_bonus;

};

} // end namespace DnD

#endif // ABILITY_H
