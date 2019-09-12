#ifndef CREATURE_BUILDER_H
#define CREATURE_BUILDER_H

#include "creature.h"
#include <string>

namespace DnD {

class CreatureBuilder {

    public:

        // Constructor
        CreatureBuilder() {}

        // Setter methods
        CreatureBuilder& set_name(const std::string& name);
        CreatureBuilder& set_size(const Size& size);
        CreatureBuilder& set_type(const std::string& type);
        CreatureBuilder& set_subtype(const std::string& subtype);
        CreatureBuilder& set_alignment(const std::string& alignment);
        CreatureBuilder& set_armor_class(const int ac);
        CreatureBuilder& set_challenge_rating(const Fraction& cr);
        CreatureBuilder& set_hit_points(const int hp);
        CreatureBuilder& set_hit_dice(const DiceSet& hit_dice);
        CreatureBuilder& set_speeds(const std::map<SpeedType,Distance>& speeds);
        CreatureBuilder& set_alternate_speeds(const std::map<std::string,std::map<SpeedType,Distance> >& alt_speeds);

        CreatureBuilder& set_strength(const int str);
        CreatureBuilder& set_dexterity(const int dex);
        CreatureBuilder& set_constitution(const int con);
        CreatureBuilder& set_intelligence(const int intl);
        CreatureBuilder& set_wisdom(const int wis);
        CreatureBuilder& set_charisma(const int chr);

        CreatureBuilder& set_skill_bonuses(const std::map<Skill,int>& skl_bns);

        CreatureBuilder& set_strength_save(const int str_sv);
        CreatureBuilder& set_dexterity_save(const int dex_sv);
        CreatureBuilder& set_constitution_save(const int con_sv);
        CreatureBuilder& set_intelligence_save(const int int_sv);
        CreatureBuilder& set_wisdom_save(const int wis_sv);
        CreatureBuilder& set_charisma_save(const int chr_sv);

        CreatureBuilder& set_perception(const int prcp);
        CreatureBuilder& set_passive_perception(const int pass_prcp);
        CreatureBuilder& set_damage_vulnerabilities(const std::vector<DamageInfo>& dmg_vuls);
        CreatureBuilder& set_damage_resistances(const std::vector<DamageInfo>& dmg_rsts);
        CreatureBuilder& set_damage_immunities(const std::vector<DamageInfo>& dmg_imns);
        CreatureBuilder& set_condition_immunities(const std::vector<Condition>& cond_imns);
        CreatureBuilder& set_senses(const std::map<SenseType, Distance>& senses);
        CreatureBuilder& set_languages(const std::string& languages);
        CreatureBuilder& set_special_abilities(const std::vector<SpecialAbility>& spcl_abls);
        CreatureBuilder& set_actions(const std::vector<Action>& actions);
        CreatureBuilder& set_legendary_actions(const std::vector<LegendaryAction>& leg_actions);

        // Building
        Creature build() const;
        void reset();
        Creature build_and_reset();


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
        std::vector<SpecialAbility> spcl_abls;
        std::vector<Action> actions;
        std::vector<LegendaryAction> leg_actions;


};

} // end namespace DnD

#endif