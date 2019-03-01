#ifndef MONSTERMANUAL_H
#define MONSTERMANUAL_H

#include <QWidget>

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
    Ui::MonsterManual *ui;
};

#endif // MONSTERMANUAL_H
