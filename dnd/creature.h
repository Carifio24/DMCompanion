#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <vector>

#include "size.h"
#include "action.h"
#include "ability.h"
#include "sense.h"
#include "damage_info.h"
#include "speed.h"
#include "fraction.h"
#include "condition.h"
#include "enumerations.h"

namespace DnD {

class Creature {

    public:

        // Getters
        std::string name() const noexcept { return _name; }
        const Size& size() const noexcept { return _size; }

        int armor_class() const noexcept { return _ac; }
        int AC() const noexcept { return _ac; }
        int hit_points() const noexcept { return _hp; }
        int HP() const noexcept { return _hp; }
        std::vector<Speed> speeds() const noexcept { return _speeds; }
        std::vector<std::pair<Speed,std::string>> alternate_speeds() const noexcept { return _alt_speeds; }

        // Ability scores
        int strength() const noexcept { return _str; }
        int dexterity() const noexcept { return _dex; }
        int constitution() const noexcept { return _con; }
        int intelligence() const noexcept { return _int; }
        int wisdom() const noexcept { return _wis; }
        int charisma() const noexcept { return _chr; }

        // Saving throw modifiers
        int strength_save() const noexcept { return _str_sv; }
        int dexterity_save() const noexcept { return _dex_sv; }
        int constitution_save() const noexcept { return _con_sv; }
        int intelligence_save() const noexcept { return _int_sv; }
        int wisdom_save() const noexcept { return _wis_sv; }
        int charisma_save() const noexcept { return _chr_sv; }

        // Other attributes
        int perception() const noexcept { return _prcp; }
        int passive_perception() const noexcept { return _pass_prcp; }
        std::vector<DamageInfo> damage_vulnerabilities() const noexcept { return _dmg_vuls; }
        std::vector<DamageInfo> damage_resistances() const noexcept { return _dmg_rsts; }
        std::vector<DamageInfo> damage_immunities() const noexcept { return _dmg_imns; }
        std::vector<const Condition*> condition_immunities() const noexcept { return _cond_imns; }
        std::vector<const Sense*> senses() const noexcept { return _senses; }
        std::vector<Ability> special_abilities() const noexcept { return _spcl_abls; }
        std::vector<Action> actions() const noexcept { return _actions; }
        std::vector<Action> legendary_actions() const noexcept { return _leg_actions; }


        // Properties
        bool is_immune_to(const DamageType& dtype);
        bool is_immune_to(const Condition& condition);
        bool is_resistant_to(const DamageType& dtype);
        bool is_vulnerable_to(const DamageType& dtype);
        bool has_speed(const SpeedType& stype);
        bool has_alternate_speed(const SpeedType& type);
        int speed_value(const SpeedType& stype);


    protected:

        // General properties
        const std::string _name;
        const Size& _size;
        const std::string _type;
        const std::string _subtype;
        const std::string _alignment;
        const Fraction _cr;

        // Combat statistics
        const int _ac;
        const int _hp;
        const std::vector<Speed> _speeds;
        const std::vector<std::pair<Speed,std::string>> _alt_speeds;

        // Ability scores
        int _str;
        int _dex;
        int _con;
        int _int;
        int _wis;
        int _chr;

        // Saving throws
        int _str_sv;
        int _dex_sv;
        int _con_sv;
        int _int_sv;
        int _wis_sv;
        int _chr_sv;

        // Other attributes
        const int _prcp;
        const std::vector<DamageInfo> _dmg_vuls;
        const std::vector<DamageInfo> _dmg_rsts;
        const std::vector<DamageInfo> _dmg_imns;
        const std::vector<const Condition*> _cond_imns;
        const std::vector<const Sense*> _senses;
        const int _pass_prcp;
        const std::string _languages; // For now
        const std::vector<Ability> _spcl_abls;
        const std::vector<Action> _actions;
        const std::vector<Action> _leg_actions;

        // To be added
        // bool speaks(const Language& language);
        // bool possible_alignment(const Alignment& alignment);

        // Constructor
        Creature(const std::string& name, const Size& size, const std::string& type, const std::string& subtype, const std::string& alignment, const Fraction& cr, const int ac, const int hp,
        const std::vector<Speed>& speeds, const std::vector<std::pair<Speed,std::string>>& alt_speeds, const int str, const int dex, const int con, const int intl, const int wis, const int chr, 
        const int str_sv, const int dex_sv, const int con_sv, const int int_sv, const int wis_sv, const int chr_sv, const int prcp, const std::vector<DamageInfo>& dmg_vuls, const std::vector<DamageInfo> dmg_rsts,
        const std::vector<DamageInfo>& dmg_imns, const std::vector<const Condition*>& cond_imns, const std::vector<Sense>& senses, const int pass_prcp, const std::string& languages, const std::vector<Ability>& spcl_abls,
        const std::vector<Action>& actions, const std::vector<Action>& leg_actions) : _name(name), _size(size), _type(type), _subtype(subtype), _alignment(alignment), _cr(cr), _ac(ac), _hp(hp),
        _speeds(speeds), _alt_speeds(alt_speeds), _str(str), _dex(dex), _con(con), _int(intl), _wis(wis), _chr(chr), _str_sv(str_sv), _dex_sv(dex_sv), _con_sv(con_sv), _int_sv(int_sv), _wis_sv(wis_sv), _chr_sv(chr_sv),
        _prcp(prcp), _dmg_vuls(dmg_vuls), _dmg_rsts(dmg_rsts), _dmg_imns(dmg_imns), _cond_imns(cond_imns), _senses(senses), _pass_prcp(pass_prcp), _languages(languages), _spcl_abls(_spcl_abls),
        _actions(actions), _leg_actions(leg_actions) {}

        friend class CreatureBuilder;
    

};

} // end namespace DnD

#endif