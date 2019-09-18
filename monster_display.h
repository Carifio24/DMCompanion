#ifndef MONSTER_DISPLAY_H
#define MONSTER_DISPLAY_H

#include "dnd/monster.h"
#include "dnd/feature.h"
#include "dnd/ability.h"
#include "dnd/damage_info.h"
#include <QString>
#include <QLabel>

QString hp_string(const DnD::Monster& m);
QString speed_string(const std::map<DnD::SpeedType, DnD::Distance>& speeds);
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
QString ability_score_text(const QString& abbr, int score, int size=3);
QString size_type_string(const DnD::Monster& m);

// Contains as_qstring(const T&) template used for T = Action, SpecialAbility, and LegendaryAction
#include "monster_display.tpp"



#endif // MONSTER_DISPLAY_H
