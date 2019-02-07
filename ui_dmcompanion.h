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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DMCompanion
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *x;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DMCompanion)
    {
        if (DMCompanion->objectName().isEmpty())
            DMCompanion->setObjectName(QStringLiteral("DMCompanion"));
        DMCompanion->resize(1225, 852);
        centralWidget = new QWidget(DMCompanion);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1221, 811));
        x = new QWidget();
        x->setObjectName(QStringLiteral("x"));
        tabWidget->addTab(x, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        DMCompanion->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DMCompanion);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1225, 19));
        DMCompanion->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DMCompanion);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DMCompanion->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DMCompanion);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DMCompanion->setStatusBar(statusBar);

        retranslateUi(DMCompanion);

        QMetaObject::connectSlotsByName(DMCompanion);
    } // setupUi

    void retranslateUi(QMainWindow *DMCompanion)
    {
        DMCompanion->setWindowTitle(QApplication::translate("DMCompanion", "DMCompanion", 0));
        tabWidget->setTabText(tabWidget->indexOf(x), QApplication::translate("DMCompanion", "spellTab", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("DMCompanion", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class DMCompanion: public Ui_DMCompanion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DMCOMPANION_H
