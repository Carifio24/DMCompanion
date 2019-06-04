#ifndef DAMAGE_INFO_H
#define DAMAGE_INFO_H

#include "Enumerations.h"

#include <string>

class DamageInfo {

    public:
        // Constructor
        DamageInfo(const DamageType& dmg_tp, const MagicType& mag_tp, const std::string& text) : _dmg_tp(dmg_tp), _mag_tp(mag_tp), _text(text) {}

        // Get member values
        const DamageType& damage_type() const noexcept { return _dmg_tp; }
        const MagicType& magic() const noexcept { return _mag_dp; }
        std::string_view text() const noexcept { return _text; }

    private:
        // Member values
        const DamageType& _dmg_tp;
        const MagicType& _mag_tp;
        const std::string _text;
};

#endif // DAMAGEINFO_H

