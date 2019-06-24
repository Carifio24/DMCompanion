#ifndef DMCOMPANION_H
#define DMCOMPANION_H

#include <QMainWindow>
#include <QModelIndex>
#include <QPixmap>
#include <QIcon>

namespace Ui {
class DMCompanion;
}

class DMCompanion : public QMainWindow
{
    Q_OBJECT

public:
    explicit DMCompanion(QWidget *parent = 0);
    ~DMCompanion();

private slots:


private:

    Ui::DMCompanion *ui;

};

#endif // DMCOMPANION_H
