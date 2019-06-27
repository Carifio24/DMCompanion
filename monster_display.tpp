#ifndef MONSTER_DISPLAY_TPP
#define MONSTER_DISPLAY_TPP

#include <QString>
#include <QStringBuilder>

template <typename ActionType>
QString as_qstring(const ActionType& act) {
    return "<b><i>" % QString::fromStdString(act.name()) % ": </i></b>" % QString::fromStdString(act.description());
}

#endif // MONSTER_DISPLAY_TPP
