#ifndef MONSTER_DISPLAY_H
#define MONSTER_DISPLAY_H

#include <DnD/monster.h>
#include <DnD/action.h>
#include <DnD/ability.h>
#include <QString>

QString hp_string(const DnD::Monster& m);
QString speed_string(const std::map<std::reference_wrapper<const DnD::SpeedType>, DnD::Distance, ref_wrap_comp>& speeds);
QString speed_string(const DnD::Monster& m);
QString saving_throws_string(const DnD::Monster& m);
QString senses_string(const DnD::Monster& m);
QString skills_string(const DnD::Monster& m);
QString damage_immunities_string(const DnD::Monster& m);
QString damage_vulnerabilities_string(const DnD::Monster& m);
QString damage_resistances_string(const DnD::Monster& m);
QString condition_immunities_string(const DnD::Monster& m);

QString ability_score_string(int x);
QString as_qstring(const DnD::DamageInfo& dinf);
QString as_qstring(const DnD::Action& act);
QString as_qstring(const DnD::Ability& abl);
QString as_qstring(const DnD::LegendaryAction& lact);



#endif // MONSTER_DISPLAY_H
