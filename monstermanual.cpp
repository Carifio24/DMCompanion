#include "monstermanual.h"
#include "ui_monstermanual.h"
#include "Parse.h"

#include <iostream>

#include <QFile>

MonsterManual::MonsterManual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonsterManual)
{
    ui->setupUi(this);

    std::cout << "Making monster manual" << std::endl;

    //Set items to be transparent
    ui->monsterTable->setStyleSheet("background-color:transparent");

    // Read and parse the monster list
    QFile qmonsterfile(":/resources/Monsters.json");
    qmonsterfile.open(QIODevice::ReadOnly);
    monsters = read_monsterfile(&qmonsterfile);
    qmonsterfile.close();

    // Populate the monster table
    populateMonsterTable(monsters);

    // Make the table view not editable
    ui->monsterTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Set the table widget to highlight its entire row
    ui->monsterTable->setSelectionBehavior(QAbstractItemView::SelectRows);

}

MonsterManual::~MonsterManual()
{
    delete ui;
}


///// Slot functions /////

///// Other methods /////

void MonsterManual::populateMonsterTable(const std::vector<Monster>& monsters) {
    ui->monsterTable->setRowCount(monsters.size());
    ui->monsterTable->setColumnCount(1);
    for (size_t i = 0; i < monsters.size(); i++) {
        ui->monsterTable->setItem(i,0,new QTableWidgetItem(QString::fromStdString(monsters[i].name)));
    }
}
