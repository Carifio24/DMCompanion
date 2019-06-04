#ifndef CREATURE_BUILDER_H
#define CREATURE_BUILDER_H

#include "Creature.h"
#include <string>

namespace DnD {

class CreatureBuilder {

    public:

        // Constructor
        CreatureBuilder();

        // Setter methods
        CreatureBuilder& set_name(const std::string& name);
        CreatureBuilder& set_size(const Size& size);
        CreatureBuilder& set_armor_class(const int ac);
        CreatureBuilder& set_hit_points(const int hp);
        CreatureBuilder& set_speeds(const std::vector<Speed>& speeds);
        CreatureBuilder& set_alternate_speeds(const std::vector<Speed>& alt_speeds);

        CreatureBuilder& set_strength(const int str);
        CreatureBuilder& set_dexterity(const int dex);
        CreatureBuilder& set_constitution(const int con);
        CreatureBuilder& set_intelligence(const int intl);
        CreatureBuilder& set_wisdom(const int wis);
        CreatureBuilder& set_charisma(const int chr);

        CreatureBuilder& set_strength_save(const int str_sv);
        CreatureBuilder& set_dexterity_save(const int dex_sv);
        CreatureBuilder& set_constitution_save(const int con_sv);
        CreatureBuilder& set_intelligence_save(const int intl_sv);
        CreatureBuilder& set_wisdom_save(const int wis_sv);
        CreatureBuilder& set_charisma_save(const int chr_sv);

        CreatureBuilder& set_perception(const int prcp);
        CreatureBuilder& set_passive_percention(const int pass_prcp);
        CreatureBuilder& set_damage_vulnerabilites(const std::vector<DamageInfo>& dmg_vuls);
        CreatureBuilder& set_damage_resistances(const std::vector<DamageInfo>& dmg_rsts);



};

} // end namespace DnD

#endif