#include "monster_display.h"

#include <QStringBuilder>

using namespace DnD;

QString hp_string(const Monster& m) {
    return QString(m.hit_points()) % "(" % QString::fromStdString(m.hit_dice().as_string()) % " + " % QString(m.hp_bonus()) % ")";
}

QString speed_string(const Monster& m) {
    QString speed_str;
    auto speeds = m.speeds();
    for (auto it = speeds.begin(); it != speeds.end(); ++it) {

    }
}
