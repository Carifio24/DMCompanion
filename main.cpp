#include "dmcompanion.h"
#include <QApplication>
#include <QStyle>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DMCompanion w;
    w.show();

    return a.exec();
}
