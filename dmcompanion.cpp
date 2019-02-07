#include "dmcompanion.h"
#include "ui_dmcompanion.h"
#include "spellbook.h"
#include <QLayout>

#include <QIcon>

DMCompanion::DMCompanion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DMCompanion)
{
    ui->setupUi(this);

    // Create the spellbook and add it as a tab
    Spellbook* spellbook = new Spellbook(this);
    QIcon icon;
    QString qs = QString("Spellbook");
    ui->tabWidget->insertTab(0, (QWidget*) spellbook, icon, qs);
    ui->tabWidget->removeTab(1);
    ui->tabWidget->removeTab(2);

    // Set the tab widget as the central widget
    setCentralWidget(ui->tabWidget);

    // Set the background image
    QPixmap bkgnd(":/resources/BookBackground.jpeg");
    bkgnd = bkgnd.scaled(this->size());
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

DMCompanion::~DMCompanion()
{
    delete ui;
}

