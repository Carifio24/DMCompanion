#include "monstermanual.h"
#include "ui_monstermanual.h"

MonsterManual::MonsterManual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonsterManual)
{
    ui->setupUi(this);
}

MonsterManual::~MonsterManual()
{
    delete ui;
}
