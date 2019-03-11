#ifndef MONSTERMANUAL_H
#define MONSTERMANUAL_H

#include <QWidget>

#include "Monster.h"

namespace Ui {
class MonsterManual;
}

class MonsterManual : public QWidget
{
    Q_OBJECT

public:
    explicit MonsterManual(QWidget *parent = 0);
    ~MonsterManual();

private:

    void populateMonsterTable(const std::vector<Monster>& monsters);

    Ui::MonsterManual *ui;
    std::vector<Monster> monsters;
};

#endif // MONSTERMANUAL_H
