#ifndef DAMAGE_INFO_H
#define DAMAGE_INFO_H

#include "damage_type.h"
#include "magic_type.h"

#include <string>
#include <functional>

namespace DnD {

class DamageInfo {

    public:
        // Constructor
        DamageInfo(const DamageType& dmg_tp, const MagicType& mag_tp, const std::string& text) : _dmg_tp(dmg_tp), _mag_tp(mag_tp), _text(text) {}

        // Get member values
        const DamageType& damage_type() const noexcept { return _dmg_tp.get(); }
        const MagicType& magic() const noexcept { return _mag_tp.get(); }
        std::string text() const noexcept { return _text; }

    private:
        // Member values
        std::reference_wrapper<const DamageType> _dmg_tp;
        std::reference_wrapper<const MagicType> _mag_tp;
        std::string _text;
};

} // end namespace DnD

#endif // DAMAGEINFO_H

