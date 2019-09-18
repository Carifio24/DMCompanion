#ifndef MONSTER_BUILDER_H
#define MONSTER_BUILDER_H

#include "monster.h"
#include <string>

namespace DnD {

class MonsterBuilder {

    public:

        // Constructor
        MonsterBuilder() {}

        // Setter methods
        MonsterBuilder& set_name(const std::string& name);
        MonsterBuilder& set_size(const Size& size);
        MonsterBuilder& set_type(const std::string& type);
        MonsterBuilder& set_subtype(const std::string& subtype);
        MonsterBuilder& set_alignment(const std::string& alignment);
        MonsterBuilder& set_armor_class(int ac);
        MonsterBuilder& set_challenge_rating(const Fraction& cr);
        MonsterBuilder& set_hit_points(int hp);
        MonsterBuilder& set_hit_dice(const DiceSet& hit_dice);
        MonsterBuilder& set_speeds(const std::map<SpeedType,Distance>& speeds);
        MonsterBuilder& set_alternate_speeds(const std::map<std::string,std::map<SpeedType,Distance> >& alt_speeds);

        MonsterBuilder& set_strength(int str);
        MonsterBuilder& set_dexterity(int dex);
        MonsterBuilder& set_constitution(int con);
        MonsterBuilder& set_intelligence(int intl);
        MonsterBuilder& set_wisdom(int wis);
        MonsterBuilder& set_charisma(int chr);

        MonsterBuilder& set_skill_bonuses(const std::map<Skill,int>& skl_bns);

        MonsterBuilder& set_strength_save(int str_sv);
        MonsterBuilder& set_dexterity_save(int dex_sv);
        MonsterBuilder& set_constitution_save(int con_sv);
        MonsterBuilder& set_intelligence_save(int int_sv);
        MonsterBuilder& set_wisdom_save(int wis_sv);
        MonsterBuilder& set_charisma_save(int chr_sv);

        MonsterBuilder& set_perception(int prcp);
        MonsterBuilder& set_passive_perception(int pass_prcp);
        MonsterBuilder& set_damage_vulnerabilities(const std::vector<DamageInfo>& dmg_vuls);
        MonsterBuilder& set_damage_resistances(const std::vector<DamageInfo>& dmg_rsts);
        MonsterBuilder& set_damage_immunities(const std::vector<DamageInfo>& dmg_imns);
        MonsterBuilder& set_condition_immunities(const std::vector<Condition>& cond_imns);
        MonsterBuilder& set_senses(const std::map<SenseType, Distance>& senses);
        MonsterBuilder& set_languages(const std::string& languages);
        MonsterBuilder& set_special_abilities(const std::vector<Feature>& spcl_abls);
        MonsterBuilder& set_actions(const std::vector<Feature>& actions);
        MonsterBuilder& set_reactions(const std::vector<Feature>& reactions);
        MonsterBuilder& set_legendary_actions(const std::vector<Feature>& leg_actions);

        // Building
        Monster build() const;
        void reset();
        Monster build_and_reset();


    protected:

        // General properties
        std::string name;
        Size size = Size::Medium;
        std::string type;
        std::string subtype;
        std::string alignment;
        Fraction cr;
        DiceSet hit_dice;

        // Combat statistics
        int ac;
        int hp;
        std::map<SpeedType,Distance> speeds;
        std::map<std::string,std::map<SpeedType,Distance> > alt_speeds;

        // Ability scores
        int str;
        int dex;
        int con;
        int intl;
        int wis;
        int chr;

        // Saving throws
        int str_sv;
        int dex_sv;
        int con_sv;
        int int_sv;
        int wis_sv;
        int chr_sv;

        // Skill bonuses
        std::map<Skill,int> skl_bns;

        // Other attributes
        int prcp;
        std::vector<DamageInfo> dmg_vuls;
        std::vector<DamageInfo> dmg_rsts;
        std::vector<DamageInfo> dmg_imns;
        std::vector<Condition> cond_imns;
        std::map<SenseType, Distance> senses;
        int pass_prcp;
        std::string languages; // For now
        std::vector<Feature> spcl_abls;
        std::vector<Feature> actions;
        std::vector<Feature> reactions;
        std::vector<Feature> leg_actions;


};

} // end namespace DnD

#endif