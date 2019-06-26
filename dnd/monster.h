#ifndef MONSTER_H
#define MONSTER_H

#include "creature.h"

#include <utility>

namespace DnD {

class Monster : public Creature {

    public:
        std::string image_filename() const noexcept { return _image_filename; }

        // Constructor
         Monster(const std::string& name, const Size& size, const std::string& type, const std::string& subtype, const std::string& alignment, const Fraction& cr, const DiceSet& hit_dice, const int ac, const int hp,
        const std::map<std::reference_wrapper<const SpeedType>,Distance,ref_wrap_comp>& speeds, const std::map<std::string,std::map<std::reference_wrapper<const SpeedType>,Distance,ref_wrap_comp>>& alt_speeds, const int str, const int dex, const int con, const int intl, const int wis, const int chr, 
        const int str_sv, const int dex_sv, const int con_sv, const int int_sv, const int wis_sv, const int chr_sv, const std::map<std::reference_wrapper<const Skill>,int,ref_wrap_comp>& skl_bns, const int prcp, const std::vector<DamageInfo>& dmg_vuls, const std::vector<DamageInfo>& dmg_rsts,
        const std::vector<DamageInfo>& dmg_imns, const std::vector<std::reference_wrapper<const Condition>>& cond_imns, const std::map<std::reference_wrapper<const SenseType>, Distance, ref_wrap_comp>& senses, const int pass_prcp, const std::string& languages, const std::vector<SpecialAbility>& spcl_abls,
        const std::vector<Action>& actions, const std::vector<LegendaryAction>& leg_actions, const std::string& image_filename)
        : Creature(name, size, type, subtype, alignment, cr, hit_dice, ac, hp, speeds, alt_speeds, str, dex, con, intl, wis, chr, str_sv, dex_sv, con_sv, int_sv, wis_sv, chr_sv, skl_bns, prcp, dmg_vuls, dmg_rsts, dmg_imns, cond_imns, senses, pass_prcp, languages, spcl_abls, actions, leg_actions), _image_filename(image_filename) {}

        // Default constructor
        Monster() : Creature(), _image_filename(""s) {}

    protected:
        std::string _image_filename;
};

} // end namespace DnD

#endif // MONSTER_H
