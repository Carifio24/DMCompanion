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
#include <QtWidgets/QLineEdit>
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
    QLineEdit *searchBar;
    QTableWidget *monsterTable;
    QVBoxLayout *dataLayout;
    QLabel *nameLabel;
    QLabel *sizeTypeLabel;
    QHBoxLayout *statsImageLayout;
    QVBoxLayout *statsLayout;
    QLabel *acLabel;
    QLabel *speedLabel;
    QLabel *hpLabel;
    QLabel *savingThrowsLabel;
    QLabel *sensesLabel;
    QLabel *damageImmunitiesLabel;
    QLabel *languagesLabel;
    QLabel *conditionImmunitiesLabel;
    QLabel *challengeRatingLabel;
    QLabel *damageResistancesLabel;
    QLabel *damageVulnerabilitiesLabel;
    QLabel *skillsLabel;
    QLabel *imageLabel;
    QHBoxLayout *abilityScoresLayout;
    QLabel *strLabel;
    QLabel *dexLabel;
    QLabel *conLabel;
    QLabel *intLabel;
    QLabel *wisLabel;
    QLabel *chaLabel;
    QScrollArea *abilitiesScrollArea;
    QWidget *abilitiesContents;
    QVBoxLayout *verticalLayout;
    QLabel *abilitiesLabel;

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
        searchBar = new QLineEdit(MonsterManual);
        searchBar->setObjectName(QString::fromUtf8("searchBar"));
        searchBar->setStyleSheet(QString::fromUtf8("background:transparent"));

        leftLayout->addWidget(searchBar);

        monsterTable = new QTableWidget(MonsterManual);
        monsterTable->setObjectName(QString::fromUtf8("monsterTable"));
        monsterTable->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(monsterTable->sizePolicy().hasHeightForWidth());
        monsterTable->setSizePolicy(sizePolicy);
        monsterTable->setAutoFillBackground(false);
        monsterTable->setStyleSheet(QString::fromUtf8("background:transparent"));
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

        sizeTypeLabel = new QLabel(MonsterManual);
        sizeTypeLabel->setObjectName(QString::fromUtf8("sizeTypeLabel"));
        sizeTypeLabel->setStyleSheet(QString::fromUtf8("font : italic"));
        sizeTypeLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        dataLayout->addWidget(sizeTypeLabel);

        statsImageLayout = new QHBoxLayout();
        statsImageLayout->setObjectName(QString::fromUtf8("statsImageLayout"));
        statsLayout = new QVBoxLayout();
        statsLayout->setObjectName(QString::fromUtf8("statsLayout"));
        acLabel = new QLabel(MonsterManual);
        acLabel->setObjectName(QString::fromUtf8("acLabel"));

        statsLayout->addWidget(acLabel);

        speedLabel = new QLabel(MonsterManual);
        speedLabel->setObjectName(QString::fromUtf8("speedLabel"));

        statsLayout->addWidget(speedLabel);

        hpLabel = new QLabel(MonsterManual);
        hpLabel->setObjectName(QString::fromUtf8("hpLabel"));

        statsLayout->addWidget(hpLabel);

        savingThrowsLabel = new QLabel(MonsterManual);
        savingThrowsLabel->setObjectName(QString::fromUtf8("savingThrowsLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(savingThrowsLabel->sizePolicy().hasHeightForWidth());
        savingThrowsLabel->setSizePolicy(sizePolicy1);
        savingThrowsLabel->setWordWrap(true);

        statsLayout->addWidget(savingThrowsLabel);

        sensesLabel = new QLabel(MonsterManual);
        sensesLabel->setObjectName(QString::fromUtf8("sensesLabel"));
        sizePolicy1.setHeightForWidth(sensesLabel->sizePolicy().hasHeightForWidth());
        sensesLabel->setSizePolicy(sizePolicy1);
        sensesLabel->setWordWrap(true);

        statsLayout->addWidget(sensesLabel);

        damageImmunitiesLabel = new QLabel(MonsterManual);
        damageImmunitiesLabel->setObjectName(QString::fromUtf8("damageImmunitiesLabel"));
        sizePolicy1.setHeightForWidth(damageImmunitiesLabel->sizePolicy().hasHeightForWidth());
        damageImmunitiesLabel->setSizePolicy(sizePolicy1);
        damageImmunitiesLabel->setWordWrap(true);

        statsLayout->addWidget(damageImmunitiesLabel);

        languagesLabel = new QLabel(MonsterManual);
        languagesLabel->setObjectName(QString::fromUtf8("languagesLabel"));
        sizePolicy1.setHeightForWidth(languagesLabel->sizePolicy().hasHeightForWidth());
        languagesLabel->setSizePolicy(sizePolicy1);
        languagesLabel->setWordWrap(true);

        statsLayout->addWidget(languagesLabel);

        conditionImmunitiesLabel = new QLabel(MonsterManual);
        conditionImmunitiesLabel->setObjectName(QString::fromUtf8("conditionImmunitiesLabel"));
        sizePolicy1.setHeightForWidth(conditionImmunitiesLabel->sizePolicy().hasHeightForWidth());
        conditionImmunitiesLabel->setSizePolicy(sizePolicy1);
        conditionImmunitiesLabel->setWordWrap(true);

        statsLayout->addWidget(conditionImmunitiesLabel);

        challengeRatingLabel = new QLabel(MonsterManual);
        challengeRatingLabel->setObjectName(QString::fromUtf8("challengeRatingLabel"));
        sizePolicy1.setHeightForWidth(challengeRatingLabel->sizePolicy().hasHeightForWidth());
        challengeRatingLabel->setSizePolicy(sizePolicy1);
        challengeRatingLabel->setWordWrap(true);

        statsLayout->addWidget(challengeRatingLabel);

        damageResistancesLabel = new QLabel(MonsterManual);
        damageResistancesLabel->setObjectName(QString::fromUtf8("damageResistancesLabel"));
        sizePolicy1.setHeightForWidth(damageResistancesLabel->sizePolicy().hasHeightForWidth());
        damageResistancesLabel->setSizePolicy(sizePolicy1);
        damageResistancesLabel->setWordWrap(true);

        statsLayout->addWidget(damageResistancesLabel);

        damageVulnerabilitiesLabel = new QLabel(MonsterManual);
        damageVulnerabilitiesLabel->setObjectName(QString::fromUtf8("damageVulnerabilitiesLabel"));
        sizePolicy1.setHeightForWidth(damageVulnerabilitiesLabel->sizePolicy().hasHeightForWidth());
        damageVulnerabilitiesLabel->setSizePolicy(sizePolicy1);
        damageVulnerabilitiesLabel->setWordWrap(true);

        statsLayout->addWidget(damageVulnerabilitiesLabel);

        skillsLabel = new QLabel(MonsterManual);
        skillsLabel->setObjectName(QString::fromUtf8("skillsLabel"));
        sizePolicy1.setHeightForWidth(skillsLabel->sizePolicy().hasHeightForWidth());
        skillsLabel->setSizePolicy(sizePolicy1);
        skillsLabel->setWordWrap(true);

        statsLayout->addWidget(skillsLabel);


        statsImageLayout->addLayout(statsLayout);

        imageLabel = new QLabel(MonsterManual);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setAlignment(Qt::AlignCenter);

        statsImageLayout->addWidget(imageLabel);


        dataLayout->addLayout(statsImageLayout);

        abilityScoresLayout = new QHBoxLayout();
        abilityScoresLayout->setObjectName(QString::fromUtf8("abilityScoresLayout"));
        strLabel = new QLabel(MonsterManual);
        strLabel->setObjectName(QString::fromUtf8("strLabel"));
        strLabel->setAlignment(Qt::AlignCenter);

        abilityScoresLayout->addWidget(strLabel);

        dexLabel = new QLabel(MonsterManual);
        dexLabel->setObjectName(QString::fromUtf8("dexLabel"));
        dexLabel->setAlignment(Qt::AlignCenter);

        abilityScoresLayout->addWidget(dexLabel);

        conLabel = new QLabel(MonsterManual);
        conLabel->setObjectName(QString::fromUtf8("conLabel"));
        conLabel->setAlignment(Qt::AlignCenter);

        abilityScoresLayout->addWidget(conLabel);

        intLabel = new QLabel(MonsterManual);
        intLabel->setObjectName(QString::fromUtf8("intLabel"));
        intLabel->setAlignment(Qt::AlignCenter);

        abilityScoresLayout->addWidget(intLabel);

        wisLabel = new QLabel(MonsterManual);
        wisLabel->setObjectName(QString::fromUtf8("wisLabel"));
        wisLabel->setAlignment(Qt::AlignCenter);

        abilityScoresLayout->addWidget(wisLabel);

        chaLabel = new QLabel(MonsterManual);
        chaLabel->setObjectName(QString::fromUtf8("chaLabel"));
        chaLabel->setAlignment(Qt::AlignCenter);

        abilityScoresLayout->addWidget(chaLabel);


        dataLayout->addLayout(abilityScoresLayout);

        abilitiesScrollArea = new QScrollArea(MonsterManual);
        abilitiesScrollArea->setObjectName(QString::fromUtf8("abilitiesScrollArea"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(abilitiesScrollArea->sizePolicy().hasHeightForWidth());
        abilitiesScrollArea->setSizePolicy(sizePolicy2);
        abilitiesScrollArea->setLayoutDirection(Qt::LeftToRight);
        abilitiesScrollArea->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        abilitiesScrollArea->setFrameShape(QFrame::NoFrame);
        abilitiesScrollArea->setFrameShadow(QFrame::Plain);
        abilitiesScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        abilitiesScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        abilitiesScrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        abilitiesScrollArea->setWidgetResizable(true);
        abilitiesScrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        abilitiesContents = new QWidget();
        abilitiesContents->setObjectName(QString::fromUtf8("abilitiesContents"));
        abilitiesContents->setGeometry(QRect(0, 0, 699, 434));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(abilitiesContents->sizePolicy().hasHeightForWidth());
        abilitiesContents->setSizePolicy(sizePolicy3);
        verticalLayout = new QVBoxLayout(abilitiesContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        abilitiesLabel = new QLabel(abilitiesContents);
        abilitiesLabel->setObjectName(QString::fromUtf8("abilitiesLabel"));
        abilitiesLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        abilitiesLabel->setWordWrap(true);

        verticalLayout->addWidget(abilitiesLabel);

        abilitiesScrollArea->setWidget(abilitiesContents);

        dataLayout->addWidget(abilitiesScrollArea);

        dataLayout->setStretch(0, 1);
        dataLayout->setStretch(2, 3);
        dataLayout->setStretch(3, 1);
        dataLayout->setStretch(4, 5);

        horizontalLayout->addLayout(dataLayout);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 5);

        retranslateUi(MonsterManual);

        QMetaObject::connectSlotsByName(MonsterManual);
    } // setupUi

    void retranslateUi(QWidget *MonsterManual)
    {
        MonsterManual->setWindowTitle(QApplication::translate("MonsterManual", "Form", nullptr));
        searchBar->setPlaceholderText(QApplication::translate("MonsterManual", "Search", nullptr));
        nameLabel->setText(QString());
        sizeTypeLabel->setText(QString());
        acLabel->setText(QString());
        speedLabel->setText(QString());
        hpLabel->setText(QString());
        savingThrowsLabel->setText(QString());
        sensesLabel->setText(QString());
        damageImmunitiesLabel->setText(QString());
        languagesLabel->setText(QString());
        conditionImmunitiesLabel->setText(QString());
        challengeRatingLabel->setText(QString());
        damageResistancesLabel->setText(QString());
        damageVulnerabilitiesLabel->setText(QString());
        skillsLabel->setText(QString());
        imageLabel->setText(QString());
        strLabel->setText(QString());
        dexLabel->setText(QString());
        conLabel->setText(QString());
        intLabel->setText(QString());
        wisLabel->setText(QString());
        chaLabel->setText(QString());
        abilitiesLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MonsterManual: public Ui_MonsterManual {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONSTERMANUAL_H
