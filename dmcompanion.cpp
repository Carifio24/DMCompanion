#include "dmcompanion.h"
#include "ui_dmcompanion.h"
#include "spellbook.h"
#include "monstermanual.h"
#include <QLayout>

#include <QIcon>
#include <QFontDatabase>

DMCompanion::DMCompanion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DMCompanion)
{
    ui->setupUi(this);

//    Create the spellbook and add it as a tab
//    Spellbook* spellbook = new Spellbook(this);
//    QIcon icon;
//    QString sbqs = QString("Spellbook");
//    ui->tabWidget->insertTab(0, (QWidget*) spellbook, icon, sbqs);
//    ui->tabWidget->removeTab(1);
//    ui->tabWidget->removeTab(2);
//    MonsterManual* monsterManual = new MonsterManual(this);
//    QString mmqs = QString("Monster Manual");
//    ui->tabWidget->insertTab(1, (QWidget*) monsterManual, icon, mmqs);


    // Set the tab widget as the central widget
    setCentralWidget(ui->tabWidget);

    // Set the first tab to be selected
    ui->tabWidget->setCurrentIndex(0);

    // Set the background image
    QPixmap bkgnd(background);
    bkgnd = bkgnd.scaled(this->size());
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    // Add the Cloister Black font
    QFontDatabase::addApplicationFont(":/fonts/cloister_black.ttf");
}

DMCompanion::~DMCompanion()
{
    delete ui;
}

void DMCompanion::resizeEvent(QResizeEvent* evt) {
    // We resize the background image when the window is resized
    QPixmap bkgnd(background);
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette p = palette(); //copy current, not create new
    p.setBrush(QPalette::Background, bkgnd);
    setPalette(p);

    // Call the base implementation
    QMainWindow::resizeEvent(evt);
}

