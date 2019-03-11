/********************************************************************************
** Form generated from reading UI file 'monstermanual.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONSTERMANUAL_H
#define UI_MONSTERMANUAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MonsterManual
{
public:
    QTableWidget *monsterTable;
    QLabel *minCRlabel;
    QLabel *maxCRlabel;

    void setupUi(QWidget *MonsterManual)
    {
        if (MonsterManual->objectName().isEmpty())
            MonsterManual->setObjectName(QStringLiteral("MonsterManual"));
        MonsterManual->resize(1005, 925);
        monsterTable = new QTableWidget(MonsterManual);
        monsterTable->setObjectName(QStringLiteral("monsterTable"));
        monsterTable->setGeometry(QRect(40, 90, 551, 751));
        monsterTable->setShowGrid(false);
        monsterTable->setGridStyle(Qt::NoPen);
        monsterTable->setSortingEnabled(false);
        monsterTable->horizontalHeader()->setVisible(false);
        monsterTable->horizontalHeader()->setHighlightSections(false);
        monsterTable->horizontalHeader()->setStretchLastSection(true);
        monsterTable->verticalHeader()->setVisible(false);
        monsterTable->verticalHeader()->setHighlightSections(false);
        minCRlabel = new QLabel(MonsterManual);
        minCRlabel->setObjectName(QStringLiteral("minCRlabel"));
        minCRlabel->setGeometry(QRect(50, 50, 81, 16));
        maxCRlabel = new QLabel(MonsterManual);
        maxCRlabel->setObjectName(QStringLiteral("maxCRlabel"));
        maxCRlabel->setGeometry(QRect(150, 50, 81, 16));

        retranslateUi(MonsterManual);

        QMetaObject::connectSlotsByName(MonsterManual);
    } // setupUi

    void retranslateUi(QWidget *MonsterManual)
    {
        MonsterManual->setWindowTitle(QApplication::translate("MonsterManual", "Form", 0));
        minCRlabel->setText(QApplication::translate("MonsterManual", "Minimum CR", 0));
        maxCRlabel->setText(QApplication::translate("MonsterManual", "Maximum CR", 0));
    } // retranslateUi

};

namespace Ui {
    class MonsterManual: public Ui_MonsterManual {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONSTERMANUAL_H
