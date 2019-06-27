#ifndef MONSTERMANUAL_H
#define MONSTERMANUAL_H

#include <QWidget>

#include <DnD/monster.h>

namespace Ui {
class MonsterManual;
}

class MonsterManual : public QWidget
{
    Q_OBJECT

public:
    explicit MonsterManual(QWidget *parent = 0);
    ~MonsterManual();

private slots:
    void on_monsterTable_clicked(const QModelIndex &index);

    void on_monsterTable_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

private:

    void populate_monster_table();
    void display_monster_data(const DnD::Monster& m);
    static const int image_width = 300;
    static const int image_height = 300;

    Ui::MonsterManual *ui;
    QVector<DnD::Monster> monsters;
};

#endif // MONSTERMANUAL_H
