#ifndef MONSTER_H
#define MONSTER_H

#include "enumerations.h"
#include "ability.h"
#include "action.h"
#include "alignment.h"
#include "fraction.h"
#include "damageinfo.h"

#include "Creature.h"

#include <utility>

namespace DnD {

class Monster : public Creature {

    public:
        int history() const noexcept { return _history; }
        std::string image_filename() const noexcept { return _image_filename; }

    protected:
        const int _history;
        const std::string _image_filename;
        
        // Constructor
        // Constructor
        Monster(const int name, const Size& size, const std::string& type, const std::string& subtype, const std::string& alignment, const Fraction& cr, const int ac, const int hp,
        const std::vector<Speed>& speeds, const std::vector<std::pair<Speed,std::string>>& alt_speeds, const int str, const int dex, const int con, const int intl, const int wis, const int chr, 
        const int str_sv, const int dex_sv, const int con_sv, const int int_sv, const int wis_sv, const int chr_sv, const int prcp, const std::vector<DamageInfo>& dmg_vuls, const std::vector<DamageInfo> dmg_rsts,
        const std::vector<DamageInfo>& dmg_imns, const std::vector<Condition* const>& cond_imns, const std::vector<Sense>& senses, const int pass_prcp, const std::string& languages, const std::vector<Ability>& spcl_abls,
        const std::vector<Action>& actions, const std::vector<Action>& leg_actions, const int history, const std::string& image_filename)
        : Creature(name, size, type, subtype, alignment, cr, ac, hp, speeds, alt_speeds, str, dex, con, intl, wis, chr, str_sv, dex_sv, con_sv, int_sv, wis_sv, chr_sv, prcp, dmg_vuls, dmg_rsts, dmg_imns, cond_imns, senses, pass_prcp, languages, spcl_abls, actions, leg_actions), _history(history), _image_filename(image_filename) {}

        friend class MonsterBuilder;


};

} // end namespace DnD

#endif // MONSTER_H
