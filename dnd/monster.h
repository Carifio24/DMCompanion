#ifndef MONSTER_H
#define MONSTER_H

#include <map>
#include <array>
#include <string>
#include <vector>

#include "size.h"
#include "feature.h"
#include "distance_type.h"
#include "sense.h"
#include "speed_type.h"
#include "damage_info.h"
#include "fraction.h"
#include "condition.h"
#include "enumerations.h"
#include "skill.h"

namespace DnD {

using namespace std::literals::string_literals;

class Monster {

    public:

        // Getters
        std::string name() const noexcept { return _name; }
        const Size& size() const noexcept { return _size; }
        std::string type() const noexcept { return _type; }
        std::string subtype() const noexcept { return _subtype; }
        std::string alignment() const noexcept { return _alignment; }

        int armor_class() const noexcept { return _ac; }
        int AC() const noexcept { return _ac; }
        int hit_points() const noexcept { return _hp; }
        int HP() const noexcept { return _hp; }
        DiceSet hit_dice() const noexcept { return _hit_dice; }
        Fraction challenge_rating() const noexcept { return _cr; }

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

        // Skill bonuses
        std::map<Skill,int> skill_bonuses() const noexcept { return _skl_bns; }

        // Other attributes
        int perception() const noexcept { return _prcp; }
        int passive_perception() const noexcept { return _pass_prcp; }
        std::vector<DamageInfo> damage_vulnerabilities() const noexcept { return _dmg_vuls; }
        std::vector<DamageInfo> damage_resistances() const noexcept { return _dmg_rsts; }
        std::vector<DamageInfo> damage_immunities() const noexcept { return _dmg_imns; }
        std::vector<Condition> condition_immunities() const noexcept { return _cond_imns; }
        std::map<SenseType, Distance> senses() const noexcept { return _senses; }
        std::string languages() const noexcept { return _languages; }
        std::vector<Feature> special_abilities() const noexcept { return _spcl_abls; }
        std::vector<Feature> actions() const noexcept { return _actions; }
        std::vector<Feature> legendary_actions() const noexcept { return _leg_actions; }
        auto speeds() const noexcept { return _speeds; }
        auto alternate_speeds() const noexcept { return _alt_speeds; }
        std::array<int,6> saving_throws() const noexcept { return {_str_sv, _dex_sv, _con_sv, _int_sv, _wis_sv, _chr_sv} ;}

        // Properties
        bool is_immune_to(const DamageType& dtype) const noexcept;
        bool is_immune_to(const Condition& condition) const noexcept;
        bool is_resistant_to(const DamageType& dtype) const noexcept;
        bool is_vulnerable_to(const DamageType& dtype) const noexcept;
        bool has_speed(const SpeedType& stype) const noexcept;
        int speed_value(const SpeedType& stype) const noexcept;
        int hp_bonus() const noexcept { return _hp - _hit_dice.average_value(); }

        // Constructor
        Monster(const std::string& name, const Size& size, const std::string& type, const std::string& subtype, const std::string& alignment, const Fraction& cr, const DiceSet& hit_dice, const int ac, const int hp,
        const std::map<SpeedType,Distance>& speeds, const std::map<std::string,std::map<SpeedType,Distance> >& alt_speeds, const int str, const int dex, const int con, const int intl, const int wis, const int chr, 
        const int str_sv, const int dex_sv, const int con_sv, const int int_sv, const int wis_sv, const int chr_sv, const std::map<Skill,int>& skl_bns, const int prcp, const std::vector<DamageInfo>& dmg_vuls, const std::vector<DamageInfo>& dmg_rsts,
        const std::vector<DamageInfo>& dmg_imns, const std::vector<Condition>& cond_imns, const std::map<SenseType,Distance>& senses, const int pass_prcp, const std::string& languages, const std::vector<Feature>& spcl_abls,
        const std::vector<Feature>& actions, const std::vector<Feature>& reactions, const std::vector<Feature>& leg_actions) : _name(name), _size(size), _type(type), _subtype(subtype), _alignment(alignment), _cr(cr), _hit_dice(hit_dice), _ac(ac), _hp(hp),
        _speeds(speeds), _alt_speeds(alt_speeds), _str(str), _dex(dex), _con(con), _int(intl), _wis(wis), _chr(chr), _str_sv(str_sv), _dex_sv(dex_sv), _con_sv(con_sv), _int_sv(int_sv), _wis_sv(wis_sv), _chr_sv(chr_sv), _skl_bns(skl_bns),
        _prcp(prcp), _dmg_vuls(dmg_vuls), _dmg_rsts(dmg_rsts), _dmg_imns(dmg_imns), _cond_imns(cond_imns), _senses(senses), _pass_prcp(pass_prcp), _languages(languages), _spcl_abls(spcl_abls),
        _actions(actions), _reactions(reactions), _leg_actions(leg_actions) {}

        // Default constructor
        Monster() : Monster(""s, Sizes::Medium, ""s, ""s, ""s, Fraction(), DiceSet(), 0, 0, std::map<SpeedType,Distance>(), std::map<std::string,std::map<SpeedType,Distance> >(),
        10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, std::map<Skill,int>(), 10, std::vector<DamageInfo>(), std::vector<DamageInfo>(), std::vector<DamageInfo>(),
        std::vector<Condition>(), std::map<SenseType, Distance>(), 10, ""s, std::vector<Feature>(),
        std::vector<Feature>(), std::vector<Feature>(), std::vector<Feature>()) {}

        // Copying
        Monster(const Monster&) = default;
        Monster& operator=(const Monster&) = default;

        // Moving
        Monster(Monster&&) = default;
        Monster& operator=(Monster&&) = default;

    protected:

        // General properties
        std::string _name;
        Size _size;
        std::string _type;
        std::string _subtype;
        std::string _alignment;
        Fraction _cr;
        DiceSet _hit_dice;

        // Combat statistics
        int _ac;
        int _hp;
        std::map<SpeedType,Distance> _speeds;
        std::map<std::string,std::map<SpeedType,Distance> > _alt_speeds;

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

        // Skill bonuses
        std::map<Skill,int> _skl_bns;

        // Other attributes
        int _prcp;
        std::vector<DamageInfo> _dmg_vuls;
        std::vector<DamageInfo> _dmg_rsts;
        std::vector<DamageInfo> _dmg_imns;
        std::vector<Condition> _cond_imns;
        std::map<SenseType,Distance> _senses;
        int _pass_prcp;
        std::string _languages; // For now
        std::vector<Feature> _spcl_abls;
        std::vector<Feature> _actions;
        std::vector<Feature> _reactions;
        std::vector<Feature> _leg_actions;

        // To be added
        // bool speaks(const Language& language);
        // bool possible_alignment(const Alignment& alignment);

        
    

};

} // end namespace DnD

#endif