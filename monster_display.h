#ifndef MONSTER_DISPLAY_H
#define MONSTER_DISPLAY_H

#include <DnD/monster.h>
#include <DnD/action.h>
#include <DnD/ability.h>
#include <DnD/damage_info.h>
#include <QString>
#include <QLabel>

QString hp_string(const DnD::Monster& m);
QString speed_string(const std::map<std::reference_wrapper<const DnD::SpeedType>, DnD::Distance, ref_wrap_comp>& speeds);
QString speed_string(const DnD::Monster& m);
QString saving_throws_string(const DnD::Monster& m);
QString senses_string(const DnD::Monster& m);
QString skills_string(const DnD::Monster& m);
QString damage_vector_string(const std::vector<DnD::DamageInfo>& v);
QString damage_immunities_string(const DnD::Monster& m);
QString damage_vulnerabilities_string(const DnD::Monster& m);
QString damage_resistances_string(const DnD::Monster& m);
QString condition_immunities_string(const DnD::Monster& m);

QString ability_score_string(int x);
QString as_qstring(const DnD::DamageInfo& dinf);
QString title_qstring(const QString& qs, int size=16);
QString ability_score_text(const QString& abbr, int score, int size=8);

// Contains as_qstring(const T&) template used for T = Action, SpecialAbility, and LegendaryAction
#include "monster_display.tpp"



#endif // MONSTER_DISPLAY_H
