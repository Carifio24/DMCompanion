#include "creature_builder.h"

#include <iostream>

namespace DnD {

CreatureBuilder& CreatureBuilder::set_name(const std::string& name) { this->name = name; return *this; }
CreatureBuilder& CreatureBuilder::set_size(const Size& size) { this->size = size; return *this; }
CreatureBuilder& CreatureBuilder::set_type(const std::string& type) { this->type = type; return *this; }
CreatureBuilder& CreatureBuilder::set_subtype(const std::string& subtype) { this->subtype = subtype; return *this; }
CreatureBuilder& CreatureBuilder::set_alignment(const std::string& alignment) { this->alignment = alignment; return *this; }
CreatureBuilder& CreatureBuilder::set_armor_class(const int ac) { this->ac = ac; return *this; }
CreatureBuilder& CreatureBuilder::set_challenge_rating(const Fraction& cr) { this->cr = cr; return *this; }
CreatureBuilder& CreatureBuilder::set_hit_points(const int hp) { this->hp = hp; return *this; }
CreatureBuilder& CreatureBuilder::set_hit_dice(const DiceSet& hit_dice) { this->hit_dice = hit_dice; return *this; }
CreatureBuilder& CreatureBuilder::set_speeds(const std::map<SpeedType,Distance>& speeds) { this->speeds = speeds; return *this; }
CreatureBuilder& CreatureBuilder::set_alternate_speeds(const std::map<std::string,std::map<SpeedType,Distance> >& alt_speeds) { this->alt_speeds = alt_speeds; return *this; }

CreatureBuilder& CreatureBuilder::set_strength(const int str) { this->str = str; return *this; }
CreatureBuilder& CreatureBuilder::set_dexterity(const int dex) { this->dex = dex; return *this; }
CreatureBuilder& CreatureBuilder::set_constitution(const int con) { this->con = con; return *this; }
CreatureBuilder& CreatureBuilder::set_intelligence(const int intl) { this->intl = intl; return *this; }
CreatureBuilder& CreatureBuilder::set_wisdom(const int wis) { this->wis = wis; return *this; }
CreatureBuilder& CreatureBuilder::set_charisma(const int chr) { this->chr = chr; return *this; }

CreatureBuilder& CreatureBuilder::set_strength_save(const int str_sv) { this->str_sv = str_sv; return *this; }
CreatureBuilder& CreatureBuilder::set_dexterity_save(const int dex_sv) { this->dex_sv = dex_sv; return *this; }
CreatureBuilder& CreatureBuilder::set_constitution_save(const int con_sv) { this->con_sv = con_sv; return *this; }
CreatureBuilder& CreatureBuilder::set_intelligence_save(const int int_sv) { this->int_sv = int_sv; return *this; }
CreatureBuilder& CreatureBuilder::set_wisdom_save(const int wis_sv) { this->wis_sv = wis_sv; return *this; }
CreatureBuilder& CreatureBuilder::set_charisma_save(const int chr_sv) { this->chr_sv = chr_sv; return *this; }

CreatureBuilder& CreatureBuilder::set_skill_bonuses(const std::map<Skill,int>& skl_bns) { this->skl_bns = skl_bns; return *this; }

CreatureBuilder& CreatureBuilder::set_perception(const int prcp) { this->prcp = prcp; return *this; }
CreatureBuilder& CreatureBuilder::set_passive_perception(const int pass_prcp) { this->pass_prcp = pass_prcp; return *this; }
CreatureBuilder& CreatureBuilder::set_damage_vulnerabilities(const std::vector<DamageInfo>& dmg_vuls) { this->dmg_vuls = dmg_vuls; return *this; }
CreatureBuilder& CreatureBuilder::set_damage_resistances(const std::vector<DamageInfo>& dmg_rsts) { this->dmg_rsts = dmg_rsts; return *this; }
CreatureBuilder& CreatureBuilder::set_damage_immunities(const std::vector<DamageInfo>& dmg_imns) { this->dmg_imns = dmg_imns; return *this; }
CreatureBuilder& CreatureBuilder::set_condition_immunities(const std::vector<Condition>& cond_imns) { this->cond_imns = cond_imns; return *this; }
CreatureBuilder& CreatureBuilder::set_senses(const std::map<SenseType, Distance>& senses) { this->senses = senses; return *this; }
CreatureBuilder& CreatureBuilder::set_languages(const std::string& languages) { this->languages = languages; return *this; }
CreatureBuilder& CreatureBuilder::set_special_abilities(const std::vector<SpecialAbility>& spcl_abls) { this->spcl_abls = spcl_abls; return *this; }
CreatureBuilder& CreatureBuilder::set_actions(const std::vector<Action>& actions) { this->actions = actions; return *this; }
CreatureBuilder& CreatureBuilder::set_legendary_actions(const std::vector<LegendaryAction>& leg_actions) { this->leg_actions = leg_actions; return *this; }


Creature CreatureBuilder::build() const {
    const std::string newline = "\n";
    std::cout << "Creating a creature with:\n";
    std::cout << "name: " << name << newline;
    std::cout << "size: " << size.name() << newline;
    std::cout << "type: " << type << newline << "subtype: " << subtype << newline << "alignment: " << alignment << newline << "languages: " << languages << newline;
    return Creature(name, size, type, subtype, alignment, cr, hit_dice, ac, hp, speeds, alt_speeds, str, dex, con, intl, wis, chr, str_sv, dex_sv, con_sv, int_sv, wis_sv, chr_sv, skl_bns, prcp, dmg_vuls, dmg_rsts, dmg_imns, cond_imns, senses, pass_prcp, languages, spcl_abls, actions, leg_actions);
}

void CreatureBuilder::reset() {
    name.clear();
    size = Size::Medium;
    type.clear();
    subtype.clear();
    alignment.clear();
    cr = Fraction();
    hit_dice = DiceSet();

    ac = 0;
    hp = 0;
    speeds.clear();
    alt_speeds.clear();

    str = 10; dex = 10; con = 10; intl = 10; wis = 10; chr = 10;
    str_sv = 0; dex_sv = 0; con_sv = 0; int_sv = 0; wis_sv = 0; chr_sv = 0;

    prcp = 0;
    dmg_vuls.clear();
    dmg_rsts.clear();
    dmg_imns.clear();
    cond_imns.clear();
    senses.clear();
    pass_prcp = 0;
    languages.clear();
    spcl_abls.clear();
    actions.clear();
    leg_actions.clear();

}

Creature CreatureBuilder::build_and_reset() {
    Creature creature = build();
    reset();
    return creature;
}

} // end namespace DnD