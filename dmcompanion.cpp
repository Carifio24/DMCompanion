#include "dmcompanion.h"
#include "ui_dmcompanion.h"
#include "spellbook.h"
#include "monstermanual.h"
#include <QLayout>

#include <QIcon>
#include <QFontDatabase>

#include <iostream>

DMCompanion::DMCompanion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DMCompanion)
{
    // Add the necessary fonts to the database
    QFontDatabase::addApplicationFont(":/resources/fonts/DejaVuSans.ttf");
    QFontDatabase::addApplicationFont(":/resources/fonts/cloister_black.ttf");
    QFontDatabase::addApplicationFont(":/resources/fonts/ScalaSans-Regular.otf");
    QFontDatabase::addApplicationFont(":/resources/fonts/ScalaSans-RegularSC.otf");
    // setFont(QFont("Sans Serif", 9, 1));

    // UI setup
    ui->setupUi(this);

    // Set the title
    setWindowTitle(QString::fromStdString("D&D 5th edition DM companion"));

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

    //std::cout << QFontDatabase::applicationFontFamilies(dvuID).at(0).toStdString() << std::endl;
    //std::cout << QFontDatabase::applicationFontFamilies(ssCID).at(0).toStdString() << std::endl;

    // Set the default font, for both the main application and for the widget in each tab
    QFont default_font = QFont("DejaVu Sans", 12, 1);
    setFont(default_font);
    for (int i = 0; i < ui->tabWidget->count(); ++i) {
        ui->tabWidget->widget(i)->setFont(default_font);
    }

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

