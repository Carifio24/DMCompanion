#include "monster_display.h"

#include <QStringList>
#include <QStringBuilder>

using namespace DnD;

QString hp_string(const Monster& m) {
    return QString(m.hit_points()) % "(" % QString::fromStdString(m.hit_dice().as_string()) % " + " % QString(m.hp_bonus()) % ")";
}

QString speed_string(const Monster& m) {

    // Make the QString for the speeds
    QStringList sl;
    auto speeds = m.speeds();
    for (auto it = speeds.cbegin(); it != speeds.cend(); ++it) {
        const auto& speed_type = it->first.get();
        if (speed_type != SpeedTypes::Walk) {
            sl << QString(speed_type.name().data()).toLower() << " ";
        }
        sl << QString::fromStdString(it->second.string());
    }
    QString sp_str = sl.join(", ");

    // Make the QString for the alternate speeds
    QStringList asl;
    auto alt_speeds = m.alternate_speeds();
    for (auto it = alt_speeds.cbegin(); it != alt_speeds.cend(); ++it) {

    }
}
