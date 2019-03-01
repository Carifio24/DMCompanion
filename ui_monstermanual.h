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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MonsterManual
{
public:
    QTableWidget *tableWidget;

    void setupUi(QWidget *MonsterManual)
    {
        if (MonsterManual->objectName().isEmpty())
            MonsterManual->setObjectName(QStringLiteral("MonsterManual"));
        MonsterManual->resize(1005, 925);
        tableWidget = new QTableWidget(MonsterManual);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(40, 180, 551, 711));

        retranslateUi(MonsterManual);

        QMetaObject::connectSlotsByName(MonsterManual);
    } // setupUi

    void retranslateUi(QWidget *MonsterManual)
    {
        MonsterManual->setWindowTitle(QApplication::translate("MonsterManual", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class MonsterManual: public Ui_MonsterManual {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONSTERMANUAL_H
