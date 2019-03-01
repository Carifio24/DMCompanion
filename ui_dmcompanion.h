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

QT_BEGIN_NAMESPACE

class Ui_DMCompanion
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    Spellbook *spellTab;
    QWidget *monsterTab;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DMCompanion)
    {
        if (DMCompanion->objectName().isEmpty())
            DMCompanion->setObjectName(QStringLiteral("DMCompanion"));
        DMCompanion->resize(1420, 862);
        centralWidget = new QWidget(DMCompanion);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(1420, 796));
        centralWidget->setAutoFillBackground(true);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(0, 0, 1421, 831));
        tabWidget->setAutoFillBackground(true);
        spellTab = new Spellbook();
        spellTab->setObjectName(QStringLiteral("spellTab"));
        spellTab->setAutoFillBackground(true);
        tabWidget->addTab(spellTab, QString());
        monsterTab = new QWidget();
        monsterTab->setObjectName(QStringLiteral("monsterTab"));
        monsterTab->setAutoFillBackground(true);
        tabWidget->addTab(monsterTab, QString());
        DMCompanion->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DMCompanion);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DMCompanion->setStatusBar(statusBar);

        retranslateUi(DMCompanion);

        tabWidget->setCurrentIndex(1);


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
