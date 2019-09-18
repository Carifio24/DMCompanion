#include "monster_builder.h"

#include <iostream>

namespace DnD {

MonsterBuilder& MonsterBuilder::set_name(const std::string& name) { this->name = name; return *this; }
MonsterBuilder& MonsterBuilder::set_size(const Size& size) { this->size = size; return *this; }
MonsterBuilder& MonsterBuilder::set_type(const std::string& type) { this->type = type; return *this; }
MonsterBuilder& MonsterBuilder::set_subtype(const std::string& subtype) { this->subtype = subtype; return *this; }
MonsterBuilder& MonsterBuilder::set_alignment(const std::string& alignment) { this->alignment = alignment; return *this; }
MonsterBuilder& MonsterBuilder::set_armor_class(const int ac) { this->ac = ac; return *this; }
MonsterBuilder& MonsterBuilder::set_challenge_rating(const Fraction& cr) { this->cr = cr; return *this; }
MonsterBuilder& MonsterBuilder::set_hit_points(const int hp) { this->hp = hp; return *this; }
MonsterBuilder& MonsterBuilder::set_hit_dice(const DiceSet& hit_dice) { this->hit_dice = hit_dice; return *this; }
MonsterBuilder& MonsterBuilder::set_speeds(const std::map<SpeedType,Distance>& speeds) { this->speeds = speeds; return *this; }
MonsterBuilder& MonsterBuilder::set_alternate_speeds(const std::map<std::string,std::map<SpeedType,Distance> >& alt_speeds) { this->alt_speeds = alt_speeds; return *this; }

MonsterBuilder& MonsterBuilder::set_strength(const int str) { this->str = str; return *this; }
MonsterBuilder& MonsterBuilder::set_dexterity(const int dex) { this->dex = dex; return *this; }
MonsterBuilder& MonsterBuilder::set_constitution(const int con) { this->con = con; return *this; }
MonsterBuilder& MonsterBuilder::set_intelligence(const int intl) { this->intl = intl; return *this; }
MonsterBuilder& MonsterBuilder::set_wisdom(const int wis) { this->wis = wis; return *this; }
MonsterBuilder& MonsterBuilder::set_charisma(const int chr) { this->chr = chr; return *this; }

MonsterBuilder& MonsterBuilder::set_strength_save(const int str_sv) { this->str_sv = str_sv; return *this; }
MonsterBuilder& MonsterBuilder::set_dexterity_save(const int dex_sv) { this->dex_sv = dex_sv; return *this; }
MonsterBuilder& MonsterBuilder::set_constitution_save(const int con_sv) { this->con_sv = con_sv; return *this; }
MonsterBuilder& MonsterBuilder::set_intelligence_save(const int int_sv) { this->int_sv = int_sv; return *this; }
MonsterBuilder& MonsterBuilder::set_wisdom_save(const int wis_sv) { this->wis_sv = wis_sv; return *this; }
MonsterBuilder& MonsterBuilder::set_charisma_save(const int chr_sv) { this->chr_sv = chr_sv; return *this; }

MonsterBuilder& MonsterBuilder::set_skill_bonuses(const std::map<Skill,int>& skl_bns) { this->skl_bns = skl_bns; return *this; }

MonsterBuilder& MonsterBuilder::set_perception(const int prcp) { this->prcp = prcp; return *this; }
MonsterBuilder& MonsterBuilder::set_passive_perception(const int pass_prcp) { this->pass_prcp = pass_prcp; return *this; }
MonsterBuilder& MonsterBuilder::set_damage_vulnerabilities(const std::vector<DamageInfo>& dmg_vuls) { this->dmg_vuls = dmg_vuls; return *this; }
MonsterBuilder& MonsterBuilder::set_damage_resistances(const std::vector<DamageInfo>& dmg_rsts) { this->dmg_rsts = dmg_rsts; return *this; }
MonsterBuilder& MonsterBuilder::set_damage_immunities(const std::vector<DamageInfo>& dmg_imns) { this->dmg_imns = dmg_imns; return *this; }
MonsterBuilder& MonsterBuilder::set_condition_immunities(const std::vector<Condition>& cond_imns) { this->cond_imns = cond_imns; return *this; }
MonsterBuilder& MonsterBuilder::set_senses(const std::map<SenseType, Distance>& senses) { this->senses = senses; return *this; }
MonsterBuilder& MonsterBuilder::set_languages(const std::string& languages) { this->languages = languages; return *this; }
MonsterBuilder& MonsterBuilder::set_special_abilities(const std::vector<Feature>& spcl_abls) { this->spcl_abls = spcl_abls; return *this; }
MonsterBuilder& MonsterBuilder::set_actions(const std::vector<Feature>& actions) { this->actions = actions; return *this; }
MonsterBuilder& MonsterBuilder::set_reactions(const std::vector<Feature>& reactions) { this->reactions = reactions; return *this; }
MonsterBuilder& MonsterBuilder::set_legendary_actions(const std::vector<Feature>& leg_actions) { this->leg_actions = leg_actions; return *this; }


Monster MonsterBuilder::build() const {
    const std::string newline = "\n";
    // std::cout << "Creating a creature with:\n";
    // std::cout << "name: " << name << newline;
    // std::cout << "size: " << size.name() << newline;
    // std::cout << "type: " << type << newline << "subtype: " << subtype << newline << "alignment: " << alignment << newline << "languages: " << languages << newline;
    return Monster(name, size, type, subtype, alignment, cr, hit_dice, ac, hp, speeds, alt_speeds, str, dex, con, intl, wis, chr, str_sv, dex_sv, con_sv, int_sv, wis_sv, chr_sv, skl_bns, prcp, dmg_vuls, dmg_rsts, dmg_imns, cond_imns, senses, pass_prcp, languages, spcl_abls, actions, reactions, leg_actions);
}

void MonsterBuilder::reset() {
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
    reactions.clear();
    leg_actions.clear();

}

Monster MonsterBuilder::build_and_reset() {
    Monster creature = build();
    reset();
    return creature;
}

} // end namespace DnD