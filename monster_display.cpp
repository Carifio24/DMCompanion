#include "monster_display.h"
#include "sort.hpp"
#include "qdisplay.h"

#include "dnd/helpers.h"
#include "dnd/string_helpers.h"

#include <QLatin1String>
#include <QStringList>
#include <QStringBuilder>

using namespace DnD;

QString hp_string(const Monster& m) {
    return QString::number(m.hit_points()) % " (" % QString::fromStdString(m.hit_dice().as_string()) % " + " % QString::number(m.hp_bonus()) % ")";
}

QString speed_string(const std::map<SpeedType,Distance>& speeds) {
    // Make the QString for the speeds
    QStringList sl;
    for (auto it = speeds.cbegin(); it != speeds.cend(); ++it) {
        const auto& speed_type = it->first;
        QString ss = QString::fromStdString(it->second.string());
        if (speed_type != SpeedTypes::Walk) {
            ss = (QString(speed_type.name().data()).toLower() % " ") + ss;
        }
        sl << ss;
    }
    QString sp_str = sl.join(", ");
    return sp_str;
}

QString speed_string(const Monster& m) {

    QString sp_str = speed_string(m.speeds());

    // Make the QString for the alternate speeds
    QStringList asl;
    auto alt_speeds = m.alternate_speeds();
    for (auto it = alt_speeds.cbegin(); it != alt_speeds.cend(); ++it) {
        QString cond = QString::fromStdString(it->first);
        QString sp = speed_string(it->second);
        QString sp_cond = sp % " " % cond;
        asl << sp_cond;
    }
    QString all_speeds;
    if (asl.size() > 0) {
        all_speeds = sp_str % " (" % asl.join(", ") % ")";
    } else {
        all_speeds = sp_str;
    }
    return all_speeds;
}

QString saving_throws_string(const Monster& m) {
    // Initialize the QStringList of ability abbreviations using a lambda
    // This will only be done on the first pass through the function
    static QStringList abilities = [] {
        QStringList al;
        for (auto x : Ability::instances()) {
            al << QString(x.abbreviation().data());
        }
        return al;
    }();

    QStringList save_strs;
    auto saves = m.saving_throws();
    std::vector<int> sorted_inds = sorted_indices(saves);
    int sv = 0;
    for (auto x : sorted_inds) {
        if ((sv = saves[x]) == 0) { continue; }
        QString sgn = sign_str(sv);
        QString s = abilities[x] % " " %sgn % QString::number(sv);
        save_strs << s;
    }
    QString sv_str = save_strs.join(", ");
    return sv_str;
}

QString senses_string(const Monster& m) {
    auto senses = m.senses();
    QStringList sl;
    for (auto it = senses.cbegin(); it != senses.cend(); ++it) {
        QLatin1String name(it->first.get().name().data());
        QString s = name % " " % QString::fromStdString(it->second.string());
        sl << s;
    }
    QString pass_prcp_str = "passive Perception " % QString::number(m.passive_perception());
    sl << pass_prcp_str;
    QString senses_str = sl.join(", ");
    return senses_str;
}

QString skills_string(const Monster& m) {
    QStringList skills_list;
    auto skill_bonuses = m.skill_bonuses();
    auto sorted_bonuses = value_sort(skill_bonuses);
    for (const auto& bonus : sorted_bonuses) {
        QString bonus_str = QLatin1String(bonus.first.get().name().data()) % " " % sign_str(bonus.second) % QString::number(bonus.second);
        skills_list << bonus_str;
    }
    QString skills_str = skills_list.join(", ");
    return skills_str;
}

QString damage_vector_string(const std::vector<DamageInfo>& v) {
    QStringList qsl;
    for (const DamageInfo& d : v) {
        qsl << as_qstring(d);
    }
    QString dvs = qsl.join(", ");
    return dvs;
}

QString damage_immunities_string(const Monster& m) {
    return damage_vector_string(m.damage_immunities());
}

QString damage_vulnerabilities_string(const Monster& m) {
    return damage_vector_string(m.damage_vulnerabilities());
}

QString damage_resistances_string(const Monster& m) {
    return damage_vector_string(m.damage_resistances());
}

QString condition_immunities_string(const Monster& m) {
    QStringList qsl;
    for (auto x : m.condition_immunities()) {
        QString xs(x.get().name().data());
        qsl << xs.toLower();
    }
    QString cis = qsl.join(", ");
    return cis;
}

QString ability_score_string(int score) {
    int mod = modifier(score);
    return QString::number(score) % " (" % sign_str(mod) % QString::number(mod) % ")";
}

QString as_qstring(const DamageInfo& dinf) {
    if (!dinf.text().empty()) {
        return QString::fromStdString(dinf.text());
    } else {
        std::string mag_str;
        if (dinf.magic() != MagicType::Any) {
            std::string s(dinf.magic().name());
            mag_str = lowercase(s);
        }
        QLatin1String dmg_str(dinf.damage_type().name().data());
        return QString::fromStdString(mag_str) % " " % dmg_str;
    }
}

QString title_qstring(const QString& qs, int size) {
    return "<font size=" % QString::number(size) % "><b>" % qs % "</b></font>";
}

QString ability_score_text(const QString& abbr, int score, int size) {
    static const QString separator = QStringLiteral("<br><font size=1><br></font>");
    static const QString double_newline = QStringLiteral("<br><br>");
    return title_qstring(abbr, size) % double_newline % ability_score_string(score);
}

QString size_type_string(const Monster& m) {
    QLatin1String size_str = QLatin1String(m.size().name().data());
    QString type_str = QString::fromStdString(m.type());
    QString subt_str;
    if (!m.subtype().empty()) {
        subt_str = " (" % QString::fromStdString(m.subtype()) % "), ";
    } else {
        subt_str = ", ";
    }
    QString alignment_str = QString::fromStdString(m.alignment());
    QString st_str = size_str % " " % type_str % subt_str % alignment_str;
    return st_str;
}
