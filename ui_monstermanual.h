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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MonsterManual
{
public:
    QTableWidget *monsterTable;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *dataLayout;
    QLabel *nameLabel;
    QLabel *basicStatsLabel;
    QHBoxLayout *abilityScoresLayout;
    QLabel *strLabel;
    QLabel *dexLabel;
    QLabel *conLabel;
    QLabel *intLabel;
    QLabel *wisLabel;
    QLabel *chaLabel;
    QLabel *extraStatsLabel;
    QScrollArea *abilitiesActionsScrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QLabel *specialAbilitiesLabel;
    QLabel *actionsLabel;
    QLabel *legendaryActionsLabel;

    void setupUi(QWidget *MonsterManual)
    {
        if (MonsterManual->objectName().isEmpty())
            MonsterManual->setObjectName(QStringLiteral("MonsterManual"));
        MonsterManual->resize(1005, 925);
        MonsterManual->setStyleSheet(QStringLiteral("background-color: transparent"));
        monsterTable = new QTableWidget(MonsterManual);
        monsterTable->setObjectName(QStringLiteral("monsterTable"));
        monsterTable->setGeometry(QRect(40, 60, 451, 841));
        monsterTable->setShowGrid(false);
        monsterTable->setGridStyle(Qt::NoPen);
        monsterTable->setSortingEnabled(false);
        monsterTable->horizontalHeader()->setVisible(false);
        monsterTable->horizontalHeader()->setHighlightSections(false);
        monsterTable->horizontalHeader()->setStretchLastSection(true);
        monsterTable->verticalHeader()->setVisible(false);
        monsterTable->verticalHeader()->setHighlightSections(false);
        verticalLayoutWidget = new QWidget(MonsterManual);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(550, 50, 431, 851));
        dataLayout = new QVBoxLayout(verticalLayoutWidget);
        dataLayout->setObjectName(QStringLiteral("dataLayout"));
        dataLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(verticalLayoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        dataLayout->addWidget(nameLabel);

        basicStatsLabel = new QLabel(verticalLayoutWidget);
        basicStatsLabel->setObjectName(QStringLiteral("basicStatsLabel"));

        dataLayout->addWidget(basicStatsLabel);

        abilityScoresLayout = new QHBoxLayout();
        abilityScoresLayout->setObjectName(QStringLiteral("abilityScoresLayout"));
        strLabel = new QLabel(verticalLayoutWidget);
        strLabel->setObjectName(QStringLiteral("strLabel"));

        abilityScoresLayout->addWidget(strLabel);

        dexLabel = new QLabel(verticalLayoutWidget);
        dexLabel->setObjectName(QStringLiteral("dexLabel"));

        abilityScoresLayout->addWidget(dexLabel);

        conLabel = new QLabel(verticalLayoutWidget);
        conLabel->setObjectName(QStringLiteral("conLabel"));

        abilityScoresLayout->addWidget(conLabel);

        intLabel = new QLabel(verticalLayoutWidget);
        intLabel->setObjectName(QStringLiteral("intLabel"));

        abilityScoresLayout->addWidget(intLabel);

        wisLabel = new QLabel(verticalLayoutWidget);
        wisLabel->setObjectName(QStringLiteral("wisLabel"));

        abilityScoresLayout->addWidget(wisLabel);

        chaLabel = new QLabel(verticalLayoutWidget);
        chaLabel->setObjectName(QStringLiteral("chaLabel"));

        abilityScoresLayout->addWidget(chaLabel);


        dataLayout->addLayout(abilityScoresLayout);

        extraStatsLabel = new QLabel(verticalLayoutWidget);
        extraStatsLabel->setObjectName(QStringLiteral("extraStatsLabel"));

        dataLayout->addWidget(extraStatsLabel);

        abilitiesActionsScrollArea = new QScrollArea(verticalLayoutWidget);
        abilitiesActionsScrollArea->setObjectName(QStringLiteral("abilitiesActionsScrollArea"));
        abilitiesActionsScrollArea->setLayoutDirection(Qt::LeftToRight);
        abilitiesActionsScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 427, 765));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        specialAbilitiesLabel = new QLabel(scrollAreaWidgetContents);
        specialAbilitiesLabel->setObjectName(QStringLiteral("specialAbilitiesLabel"));

        verticalLayout->addWidget(specialAbilitiesLabel);

        actionsLabel = new QLabel(scrollAreaWidgetContents);
        actionsLabel->setObjectName(QStringLiteral("actionsLabel"));

        verticalLayout->addWidget(actionsLabel);

        legendaryActionsLabel = new QLabel(scrollAreaWidgetContents);
        legendaryActionsLabel->setObjectName(QStringLiteral("legendaryActionsLabel"));

        verticalLayout->addWidget(legendaryActionsLabel);

        abilitiesActionsScrollArea->setWidget(scrollAreaWidgetContents);

        dataLayout->addWidget(abilitiesActionsScrollArea);


        retranslateUi(MonsterManual);

        QMetaObject::connectSlotsByName(MonsterManual);
    } // setupUi

    void retranslateUi(QWidget *MonsterManual)
    {
        MonsterManual->setWindowTitle(QApplication::translate("MonsterManual", "Form", 0));
        nameLabel->setText(QString());
        basicStatsLabel->setText(QString());
        strLabel->setText(QString());
        dexLabel->setText(QString());
        conLabel->setText(QString());
        intLabel->setText(QString());
        wisLabel->setText(QString());
        chaLabel->setText(QString());
        extraStatsLabel->setText(QString());
        specialAbilitiesLabel->setText(QString());
        actionsLabel->setText(QString());
        legendaryActionsLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MonsterManual: public Ui_MonsterManual {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONSTERMANUAL_H
