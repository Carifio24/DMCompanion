#include "monstermanual.h"
#include "ui_monstermanual.h"
#include "monster_parse.h"
#include "monster_display.h"
#include "qdisplay.h"
#include <iostream>

#include <QFile>

using namespace DnD;

MonsterManual::MonsterManual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonsterManual)
{
    ui->setupUi(this);

    std::cout << "Making monster manual" << std::endl;

    //Set items to be transparent

    // Read and parse the monster list
    QFile qmonsterfile(":/resources/Monsters.json");
    qmonsterfile.open(QIODevice::ReadOnly);
    monsters = read_monster_file(&qmonsterfile);
    qmonsterfile.close();

    // Populate the monster table
    std::cout << "About to populate monster table" << std::endl;
    populate_monster_table();

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

void MonsterManual::on_monsterTable_clicked(const QModelIndex &index)
{
    display_monster_data(monsters[index.row()]);
}

void MonsterManual::on_monsterTable_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    display_monster_data(monsters[currentRow]);
}

///// Other methods /////

void MonsterManual::populate_monster_table() {
    ui->monsterTable->setRowCount(monsters.size());
    ui->monsterTable->setColumnCount(1);
    for (int i = 0; i < monsters.size(); ++i) {
        ui->monsterTable->setItem(i,0,new QTableWidgetItem(QString::fromStdString(monsters[i].name())));
    }
}

void MonsterManual::display_monster_data(const Monster& m) {

    // Name
    std::cout << "About to display monster data" << std::endl;
    ui->nameLabel->setText(QLatin1String(m.name().data()));
    std::cout << "Displayed name: " << m.name() << std::endl;

    // Basic stats
    QString ac_str = prompt_text("Armor class", m.armor_class());
    QString hp_str = prompt_text("Hit Points", hp_string(m));
    QString speed_str = prompt_text("Speed", speed_string(m));
    ui->acLabel->setText(ac_str);
    ui->hpLabel->setText(hp_str);
    ui->speedLabel->setText(speed_str);

    // Extra stats
    set_text_if_nonempty(ui->savingThrowsLabel, "Saving Throws", saving_throws_string(m));
    set_text_if_nonempty(ui->sensesLabel, "Senses", senses_string(m));
    set_text_if_nonempty(ui->skillsLabel, "Skills", skills_string(m));
    set_text_if_nonempty(ui->languagesLabel, "Languages", QString::fromStdString(m.languages()));


}


