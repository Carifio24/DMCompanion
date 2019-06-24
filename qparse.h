#ifndef QPARSE_H
#define QPARSE_H

#include <QFile>
#include <QVector>
#include <DnD/monster.h>
#include <DnD/spell.h>

QVector<DnD::Monster> read_monster_file(QFile* monster_file);
QVector<DnD::Spell> read_spell_file(QFile* spell_file);

#endif // QPARSE_H

