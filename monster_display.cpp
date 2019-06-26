#include "monster_display.h"
#include "sort.h"
#include "qdisplay.h"

#include <DnD/string_helpers.h>

#include <QStringList>
#include <QStringBuilder>

using namespace DnD;

QString hp_string(const Monster& m) {
    return QString::number(m.hit_points()) % "(" % QString::fromStdString(m.hit_dice().as_string()) % " + " % QString::number(m.hp_bonus()) % ")";
}

QString speed_string(const std::map<std::reference_wrapper<const SpeedType>, Distance, ref_wrap_comp>& speeds) {
    // Make the QString for the speeds
    QStringList sl;
    for (auto it = speeds.cbegin(); it != speeds.cend(); ++it) {
        const auto& speed_type = it->first.get();
        if (speed_type != SpeedTypes::Walk) {
            sl << QString(speed_type.name().data()).toLower() << " ";
        }
        sl << QString::fromStdString(it->second.string());
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
    QString all_speeds = sp_str % " (" % asl.join(", ") % ")";
    return all_speeds;
}

QString saving_throws_string(const Monster& m) {
    static QStringList abilities = {
        "Str", "Dex", "Con", "Int", "Wis", "Cha"
    };
    QStringList save_strs;
    auto saves = m.saving_throws();
    std::vector<int> sorted_inds = sorted_indices(saves);
    int sv;
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

QString ability_score_string(int x) {
    return sign_str(x) % QString::number(x);
}

QString as_string(const DamageInfo& dinf) {
    if (!dinf.text().empty()) {
        return QString::fromStdString(dinf.text());
    } else {
        std::string mag_str;
        if (dinf.magic() != MagicTypes::Any) {
            std::string s(dinf.magic().name());
            mag_str = lowercase(s);
        }
        QLatin1String dmg_str(dinf.damage_type().name().data());
        return QString::fromStdString(mag_str) % " " % dmg_str;
    }
}

QString as_string(const Action& act) {
    return "<b><i>" % QString::fromStdString(act.name()) % ": </i></b>" % QString::fromStdString(act.description());
}

QString as_string(const SpecialAbility& abl) {


}
