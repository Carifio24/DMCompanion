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

    QLatin1String background{":/resources/bookbackground_2.jpg"};
    Ui::DMCompanion *ui;
    void resizeEvent(QResizeEvent* evt);

};

#endif // DMCOMPANION_H
