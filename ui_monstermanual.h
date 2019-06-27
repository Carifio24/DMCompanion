/********************************************************************************
** Form generated from reading UI file 'monstermanual.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONSTERMANUAL_H
#define UI_MONSTERMANUAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *leftLayout;
    QTableWidget *monsterTable;
    QVBoxLayout *dataLayout;
    QLabel *nameLabel;
    QLabel *imageLabel;
    QHBoxLayout *abilityScoresLayout;
    QLabel *strLabel;
    QLabel *dexLabel;
    QLabel *conLabel;
    QLabel *intLabel;
    QLabel *wisLabel;
    QLabel *chaLabel;
    QVBoxLayout *basicStatsLayout;
    QLabel *acLabel;
    QLabel *hpLabel;
    QLabel *speedLabel;
    QVBoxLayout *extraStatsLayout;
    QLabel *savingThrowsLabel;
    QLabel *sensesLabel;
    QLabel *damageImmunitiesLabel;
    QLabel *languagesLabel;
    QLabel *conditionImmunitiesLabel;
    QLabel *challengeRatingLabel;
    QLabel *damageResistancesLabel;
    QLabel *damageVulnerabilitiesLabel;
    QLabel *skillsLabel;
    QScrollArea *abilitiesActionsScrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QLabel *specialAbilitiesLabel;
    QLabel *actionsLabel;
    QLabel *legendaryActionsLabel;

    void setupUi(QWidget *MonsterManual)
    {
        if (MonsterManual->objectName().isEmpty())
            MonsterManual->setObjectName(QString::fromUtf8("MonsterManual"));
        MonsterManual->resize(1005, 925);
        MonsterManual->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        horizontalLayout = new QHBoxLayout(MonsterManual);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        leftLayout = new QVBoxLayout();
        leftLayout->setObjectName(QString::fromUtf8("leftLayout"));
        monsterTable = new QTableWidget(MonsterManual);
        monsterTable->setObjectName(QString::fromUtf8("monsterTable"));
        monsterTable->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(monsterTable->sizePolicy().hasHeightForWidth());
        monsterTable->setSizePolicy(sizePolicy);
        monsterTable->setShowGrid(false);
        monsterTable->setGridStyle(Qt::NoPen);
        monsterTable->setSortingEnabled(false);
        monsterTable->horizontalHeader()->setVisible(false);
        monsterTable->horizontalHeader()->setHighlightSections(false);
        monsterTable->horizontalHeader()->setStretchLastSection(true);
        monsterTable->verticalHeader()->setVisible(false);
        monsterTable->verticalHeader()->setHighlightSections(false);

        leftLayout->addWidget(monsterTable);


        horizontalLayout->addLayout(leftLayout);

        dataLayout = new QVBoxLayout();
        dataLayout->setSpacing(6);
        dataLayout->setObjectName(QString::fromUtf8("dataLayout"));
        dataLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        nameLabel = new QLabel(MonsterManual);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("URW Chancery L"));
        font.setPointSize(30);
        font.setItalic(true);
        nameLabel->setFont(font);
        nameLabel->setAlignment(Qt::AlignCenter);

        dataLayout->addWidget(nameLabel);

        imageLabel = new QLabel(MonsterManual);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setAlignment(Qt::AlignCenter);

        dataLayout->addWidget(imageLabel);

        abilityScoresLayout = new QHBoxLayout();
        abilityScoresLayout->setObjectName(QString::fromUtf8("abilityScoresLayout"));
        strLabel = new QLabel(MonsterManual);
        strLabel->setObjectName(QString::fromUtf8("strLabel"));

        abilityScoresLayout->addWidget(strLabel);

        dexLabel = new QLabel(MonsterManual);
        dexLabel->setObjectName(QString::fromUtf8("dexLabel"));

        abilityScoresLayout->addWidget(dexLabel);

        conLabel = new QLabel(MonsterManual);
        conLabel->setObjectName(QString::fromUtf8("conLabel"));

        abilityScoresLayout->addWidget(conLabel);

        intLabel = new QLabel(MonsterManual);
        intLabel->setObjectName(QString::fromUtf8("intLabel"));

        abilityScoresLayout->addWidget(intLabel);

        wisLabel = new QLabel(MonsterManual);
        wisLabel->setObjectName(QString::fromUtf8("wisLabel"));

        abilityScoresLayout->addWidget(wisLabel);

        chaLabel = new QLabel(MonsterManual);
        chaLabel->setObjectName(QString::fromUtf8("chaLabel"));

        abilityScoresLayout->addWidget(chaLabel);


        dataLayout->addLayout(abilityScoresLayout);

        basicStatsLayout = new QVBoxLayout();
        basicStatsLayout->setObjectName(QString::fromUtf8("basicStatsLayout"));
        acLabel = new QLabel(MonsterManual);
        acLabel->setObjectName(QString::fromUtf8("acLabel"));

        basicStatsLayout->addWidget(acLabel);

        hpLabel = new QLabel(MonsterManual);
        hpLabel->setObjectName(QString::fromUtf8("hpLabel"));

        basicStatsLayout->addWidget(hpLabel);

        speedLabel = new QLabel(MonsterManual);
        speedLabel->setObjectName(QString::fromUtf8("speedLabel"));

        basicStatsLayout->addWidget(speedLabel);


        dataLayout->addLayout(basicStatsLayout);

        extraStatsLayout = new QVBoxLayout();
        extraStatsLayout->setObjectName(QString::fromUtf8("extraStatsLayout"));
        savingThrowsLabel = new QLabel(MonsterManual);
        savingThrowsLabel->setObjectName(QString::fromUtf8("savingThrowsLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(savingThrowsLabel->sizePolicy().hasHeightForWidth());
        savingThrowsLabel->setSizePolicy(sizePolicy1);
        savingThrowsLabel->setWordWrap(true);

        extraStatsLayout->addWidget(savingThrowsLabel);

        sensesLabel = new QLabel(MonsterManual);
        sensesLabel->setObjectName(QString::fromUtf8("sensesLabel"));
        sizePolicy1.setHeightForWidth(sensesLabel->sizePolicy().hasHeightForWidth());
        sensesLabel->setSizePolicy(sizePolicy1);
        sensesLabel->setWordWrap(true);

        extraStatsLayout->addWidget(sensesLabel);

        damageImmunitiesLabel = new QLabel(MonsterManual);
        damageImmunitiesLabel->setObjectName(QString::fromUtf8("damageImmunitiesLabel"));
        sizePolicy1.setHeightForWidth(damageImmunitiesLabel->sizePolicy().hasHeightForWidth());
        damageImmunitiesLabel->setSizePolicy(sizePolicy1);
        damageImmunitiesLabel->setWordWrap(true);

        extraStatsLayout->addWidget(damageImmunitiesLabel);

        languagesLabel = new QLabel(MonsterManual);
        languagesLabel->setObjectName(QString::fromUtf8("languagesLabel"));
        sizePolicy1.setHeightForWidth(languagesLabel->sizePolicy().hasHeightForWidth());
        languagesLabel->setSizePolicy(sizePolicy1);
        languagesLabel->setWordWrap(true);

        extraStatsLayout->addWidget(languagesLabel);

        conditionImmunitiesLabel = new QLabel(MonsterManual);
        conditionImmunitiesLabel->setObjectName(QString::fromUtf8("conditionImmunitiesLabel"));
        sizePolicy1.setHeightForWidth(conditionImmunitiesLabel->sizePolicy().hasHeightForWidth());
        conditionImmunitiesLabel->setSizePolicy(sizePolicy1);
        conditionImmunitiesLabel->setWordWrap(true);

        extraStatsLayout->addWidget(conditionImmunitiesLabel);

        challengeRatingLabel = new QLabel(MonsterManual);
        challengeRatingLabel->setObjectName(QString::fromUtf8("challengeRatingLabel"));
        sizePolicy1.setHeightForWidth(challengeRatingLabel->sizePolicy().hasHeightForWidth());
        challengeRatingLabel->setSizePolicy(sizePolicy1);
        challengeRatingLabel->setWordWrap(true);

        extraStatsLayout->addWidget(challengeRatingLabel);

        damageResistancesLabel = new QLabel(MonsterManual);
        damageResistancesLabel->setObjectName(QString::fromUtf8("damageResistancesLabel"));
        sizePolicy1.setHeightForWidth(damageResistancesLabel->sizePolicy().hasHeightForWidth());
        damageResistancesLabel->setSizePolicy(sizePolicy1);
        damageResistancesLabel->setWordWrap(true);

        extraStatsLayout->addWidget(damageResistancesLabel);

        damageVulnerabilitiesLabel = new QLabel(MonsterManual);
        damageVulnerabilitiesLabel->setObjectName(QString::fromUtf8("damageVulnerabilitiesLabel"));
        sizePolicy1.setHeightForWidth(damageVulnerabilitiesLabel->sizePolicy().hasHeightForWidth());
        damageVulnerabilitiesLabel->setSizePolicy(sizePolicy1);
        damageVulnerabilitiesLabel->setWordWrap(true);

        extraStatsLayout->addWidget(damageVulnerabilitiesLabel);

        skillsLabel = new QLabel(MonsterManual);
        skillsLabel->setObjectName(QString::fromUtf8("skillsLabel"));
        sizePolicy1.setHeightForWidth(skillsLabel->sizePolicy().hasHeightForWidth());
        skillsLabel->setSizePolicy(sizePolicy1);
        skillsLabel->setWordWrap(true);

        extraStatsLayout->addWidget(skillsLabel);


        dataLayout->addLayout(extraStatsLayout);

        abilitiesActionsScrollArea = new QScrollArea(MonsterManual);
        abilitiesActionsScrollArea->setObjectName(QString::fromUtf8("abilitiesActionsScrollArea"));
        abilitiesActionsScrollArea->setLayoutDirection(Qt::LeftToRight);
        abilitiesActionsScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 697, 560));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        specialAbilitiesLabel = new QLabel(scrollAreaWidgetContents);
        specialAbilitiesLabel->setObjectName(QString::fromUtf8("specialAbilitiesLabel"));
        specialAbilitiesLabel->setTextFormat(Qt::RichText);

        verticalLayout->addWidget(specialAbilitiesLabel);

        actionsLabel = new QLabel(scrollAreaWidgetContents);
        actionsLabel->setObjectName(QString::fromUtf8("actionsLabel"));

        verticalLayout->addWidget(actionsLabel);

        legendaryActionsLabel = new QLabel(scrollAreaWidgetContents);
        legendaryActionsLabel->setObjectName(QString::fromUtf8("legendaryActionsLabel"));

        verticalLayout->addWidget(legendaryActionsLabel);

        abilitiesActionsScrollArea->setWidget(scrollAreaWidgetContents);

        dataLayout->addWidget(abilitiesActionsScrollArea);


        horizontalLayout->addLayout(dataLayout);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 5);

        retranslateUi(MonsterManual);

        QMetaObject::connectSlotsByName(MonsterManual);
    } // setupUi

    void retranslateUi(QWidget *MonsterManual)
    {
        MonsterManual->setWindowTitle(QApplication::translate("MonsterManual", "Form", nullptr));
        nameLabel->setText(QString());
        imageLabel->setText(QString());
        strLabel->setText(QString());
        dexLabel->setText(QString());
        conLabel->setText(QString());
        intLabel->setText(QString());
        wisLabel->setText(QString());
        chaLabel->setText(QString());
        acLabel->setText(QString());
        hpLabel->setText(QString());
        speedLabel->setText(QString());
        savingThrowsLabel->setText(QString());
        sensesLabel->setText(QString());
        damageImmunitiesLabel->setText(QString());
        languagesLabel->setText(QString());
        conditionImmunitiesLabel->setText(QString());
        challengeRatingLabel->setText(QString());
        damageResistancesLabel->setText(QString());
        damageVulnerabilitiesLabel->setText(QString());
        skillsLabel->setText(QString());
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
