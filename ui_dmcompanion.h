/********************************************************************************
** Form generated from reading UI file 'dmcompanion.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DMCOMPANION_H
#define UI_DMCOMPANION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <spellbook.h>
#include "monstermanual.h"

QT_BEGIN_NAMESPACE

class Ui_DMCompanion
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    Spellbook *spellTab;
    MonsterManual *monsterTab;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DMCompanion)
    {
        if (DMCompanion->objectName().isEmpty())
            DMCompanion->setObjectName(QStringLiteral("DMCompanion"));
        DMCompanion->resize(1420, 862);
        DMCompanion->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(DMCompanion);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(1420, 796));
        centralWidget->setAutoFillBackground(false);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(0, 0, 1421, 831));
        tabWidget->setMaximumSize(QSize(4000, 4000));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QStringLiteral(""));
        spellTab = new Spellbook();
        spellTab->setObjectName(QStringLiteral("spellTab"));
        spellTab->setMaximumSize(QSize(4000, 4000));
        spellTab->setAutoFillBackground(false);
        spellTab->setStyleSheet(QStringLiteral(""));
        tabWidget->addTab(spellTab, QString());
        monsterTab = new MonsterManual();
        monsterTab->setObjectName(QStringLiteral("monsterTab"));
        monsterTab->setEnabled(true);
        monsterTab->setMaximumSize(QSize(4000, 4000));
        monsterTab->setAutoFillBackground(false);
        monsterTab->setStyleSheet(QStringLiteral(""));
        tabWidget->addTab(monsterTab, QString());
        DMCompanion->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DMCompanion);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DMCompanion->setStatusBar(statusBar);

        retranslateUi(DMCompanion);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DMCompanion);
    } // setupUi

    void retranslateUi(QMainWindow *DMCompanion)
    {
        DMCompanion->setWindowTitle(QApplication::translate("DMCompanion", "Spellbook", 0));
        tabWidget->setTabText(tabWidget->indexOf(spellTab), QApplication::translate("DMCompanion", "Spellbook", 0));
        tabWidget->setTabText(tabWidget->indexOf(monsterTab), QApplication::translate("DMCompanion", "Monster Manual", 0));
    } // retranslateUi

};

namespace Ui {
    class DMCompanion: public Ui_DMCompanion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DMCOMPANION_H
