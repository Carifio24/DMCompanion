/********************************************************************************
** Form generated from reading UI file 'monstermanual.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONSTERMANUAL_H
#define UI_MONSTERMANUAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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
    QVBoxLayout *sortLayout;
    QLabel *sortLabel;
    QComboBox *sortComboBox;
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
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        MonsterManual->setFont(font);
        MonsterManual->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        horizontalLayout = new QHBoxLayout(MonsterManual);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout->setContentsMargins(5, -1, 5, -1);
        leftLayout = new QVBoxLayout();
        leftLayout->setSpacing(6);
        leftLayout->setObjectName(QString::fromUtf8("leftLayout"));
        sortLayout = new QVBoxLayout();
        sortLayout->setObjectName(QString::fromUtf8("sortLayout"));
        sortLabel = new QLabel(MonsterManual);
        sortLabel->setObjectName(QString::fromUtf8("sortLabel"));

        sortLayout->addWidget(sortLabel);

        sortComboBox = new QComboBox(MonsterManual);
        sortComboBox->setObjectName(QString::fromUtf8("sortComboBox"));
        sortComboBox->setStyleSheet(QString::fromUtf8("background-color : rgb(231,208,166)"));

        sortLayout->addWidget(sortComboBox);


        leftLayout->addLayout(sortLayout);

        searchBar = new QLineEdit(MonsterManual);
        searchBar->setObjectName(QString::fromUtf8("searchBar"));
        searchBar->setFont(font);
        searchBar->setStyleSheet(QString::fromUtf8("background:transparent"));

        leftLayout->addWidget(searchBar);

        monsterTable = new QTableWidget(MonsterManual);
        monsterTable->setObjectName(QString::fromUtf8("monsterTable"));
        monsterTable->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(monsterTable->sizePolicy().hasHeightForWidth());
        monsterTable->setSizePolicy(sizePolicy);
        monsterTable->setFont(font);
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

        leftLayout->setStretch(1, 3);
        leftLayout->setStretch(2, 7);

        horizontalLayout->addLayout(leftLayout);

        dataLayout = new QVBoxLayout();
        dataLayout->setSpacing(6);
        dataLayout->setObjectName(QString::fromUtf8("dataLayout"));
        dataLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        nameLabel = new QLabel(MonsterManual);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(30);
        font1.setItalic(true);
        nameLabel->setFont(font1);
        nameLabel->setAlignment(Qt::AlignCenter);

        dataLayout->addWidget(nameLabel);

        sizeTypeLabel = new QLabel(MonsterManual);
        sizeTypeLabel->setObjectName(QString::fromUtf8("sizeTypeLabel"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(true);
        font2.setWeight(50);
        sizeTypeLabel->setFont(font2);
        sizeTypeLabel->setStyleSheet(QString::fromUtf8("font : italic"));
        sizeTypeLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        dataLayout->addWidget(sizeTypeLabel);

        statsImageLayout = new QHBoxLayout();
        statsImageLayout->setObjectName(QString::fromUtf8("statsImageLayout"));
        statsLayout = new QVBoxLayout();
        statsLayout->setObjectName(QString::fromUtf8("statsLayout"));
        acLabel = new QLabel(MonsterManual);
        acLabel->setObjectName(QString::fromUtf8("acLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(acLabel->sizePolicy().hasHeightForWidth());
        acLabel->setSizePolicy(sizePolicy1);
        acLabel->setFont(font);

        statsLayout->addWidget(acLabel);

        speedLabel = new QLabel(MonsterManual);
        speedLabel->setObjectName(QString::fromUtf8("speedLabel"));
        speedLabel->setFont(font);

        statsLayout->addWidget(speedLabel);

        hpLabel = new QLabel(MonsterManual);
        hpLabel->setObjectName(QString::fromUtf8("hpLabel"));
        hpLabel->setFont(font);

        statsLayout->addWidget(hpLabel);

        savingThrowsLabel = new QLabel(MonsterManual);
        savingThrowsLabel->setObjectName(QString::fromUtf8("savingThrowsLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(savingThrowsLabel->sizePolicy().hasHeightForWidth());
        savingThrowsLabel->setSizePolicy(sizePolicy2);
        savingThrowsLabel->setFont(font);
        savingThrowsLabel->setWordWrap(true);

        statsLayout->addWidget(savingThrowsLabel);

        sensesLabel = new QLabel(MonsterManual);
        sensesLabel->setObjectName(QString::fromUtf8("sensesLabel"));
        sizePolicy2.setHeightForWidth(sensesLabel->sizePolicy().hasHeightForWidth());
        sensesLabel->setSizePolicy(sizePolicy2);
        sensesLabel->setFont(font);
        sensesLabel->setWordWrap(true);

        statsLayout->addWidget(sensesLabel);

        damageImmunitiesLabel = new QLabel(MonsterManual);
        damageImmunitiesLabel->setObjectName(QString::fromUtf8("damageImmunitiesLabel"));
        sizePolicy2.setHeightForWidth(damageImmunitiesLabel->sizePolicy().hasHeightForWidth());
        damageImmunitiesLabel->setSizePolicy(sizePolicy2);
        damageImmunitiesLabel->setFont(font);
        damageImmunitiesLabel->setWordWrap(true);

        statsLayout->addWidget(damageImmunitiesLabel);

        languagesLabel = new QLabel(MonsterManual);
        languagesLabel->setObjectName(QString::fromUtf8("languagesLabel"));
        sizePolicy2.setHeightForWidth(languagesLabel->sizePolicy().hasHeightForWidth());
        languagesLabel->setSizePolicy(sizePolicy2);
        languagesLabel->setFont(font);
        languagesLabel->setWordWrap(true);

        statsLayout->addWidget(languagesLabel);

        conditionImmunitiesLabel = new QLabel(MonsterManual);
        conditionImmunitiesLabel->setObjectName(QString::fromUtf8("conditionImmunitiesLabel"));
        sizePolicy2.setHeightForWidth(conditionImmunitiesLabel->sizePolicy().hasHeightForWidth());
        conditionImmunitiesLabel->setSizePolicy(sizePolicy2);
        conditionImmunitiesLabel->setFont(font);
        conditionImmunitiesLabel->setWordWrap(true);

        statsLayout->addWidget(conditionImmunitiesLabel);

        challengeRatingLabel = new QLabel(MonsterManual);
        challengeRatingLabel->setObjectName(QString::fromUtf8("challengeRatingLabel"));
        sizePolicy2.setHeightForWidth(challengeRatingLabel->sizePolicy().hasHeightForWidth());
        challengeRatingLabel->setSizePolicy(sizePolicy2);
        challengeRatingLabel->setFont(font);
        challengeRatingLabel->setWordWrap(true);

        statsLayout->addWidget(challengeRatingLabel);

        damageResistancesLabel = new QLabel(MonsterManual);
        damageResistancesLabel->setObjectName(QString::fromUtf8("damageResistancesLabel"));
        sizePolicy2.setHeightForWidth(damageResistancesLabel->sizePolicy().hasHeightForWidth());
        damageResistancesLabel->setSizePolicy(sizePolicy2);
        damageResistancesLabel->setFont(font);
        damageResistancesLabel->setWordWrap(true);

        statsLayout->addWidget(damageResistancesLabel);

        damageVulnerabilitiesLabel = new QLabel(MonsterManual);
        damageVulnerabilitiesLabel->setObjectName(QString::fromUtf8("damageVulnerabilitiesLabel"));
        sizePolicy2.setHeightForWidth(damageVulnerabilitiesLabel->sizePolicy().hasHeightForWidth());
        damageVulnerabilitiesLabel->setSizePolicy(sizePolicy2);
        damageVulnerabilitiesLabel->setFont(font);
        damageVulnerabilitiesLabel->setWordWrap(true);

        statsLayout->addWidget(damageVulnerabilitiesLabel);

        skillsLabel = new QLabel(MonsterManual);
        skillsLabel->setObjectName(QString::fromUtf8("skillsLabel"));
        sizePolicy2.setHeightForWidth(skillsLabel->sizePolicy().hasHeightForWidth());
        skillsLabel->setSizePolicy(sizePolicy2);
        skillsLabel->setFont(font);
        skillsLabel->setWordWrap(true);

        statsLayout->addWidget(skillsLabel);


        statsImageLayout->addLayout(statsLayout);

        imageLabel = new QLabel(MonsterManual);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy3);
        imageLabel->setFont(font);
        imageLabel->setFrameShape(QFrame::Box);
        imageLabel->setLineWidth(3);

        statsImageLayout->addWidget(imageLabel);


        dataLayout->addLayout(statsImageLayout);

        abilityScoresLayout = new QHBoxLayout();
        abilityScoresLayout->setObjectName(QString::fromUtf8("abilityScoresLayout"));
        strLabel = new QLabel(MonsterManual);
        strLabel->setObjectName(QString::fromUtf8("strLabel"));
        strLabel->setFont(font);
        strLabel->setAlignment(Qt::AlignCenter);

        abilityScoresLayout->addWidget(strLabel);

        dexLabel = new QLabel(MonsterManual);
        dexLabel->setObjectName(QString::fromUtf8("dexLabel"));
        dexLabel->setFont(font);
        dexLabel->setAlignment(Qt::AlignCenter);

        abilityScoresLayout->addWidget(dexLabel);

        conLabel = new QLabel(MonsterManual);
        conLabel->setObjectName(QString::fromUtf8("conLabel"));
        conLabel->setFont(font);
        conLabel->setAlignment(Qt::AlignCenter);

        abilityScoresLayout->addWidget(conLabel);

        intLabel = new QLabel(MonsterManual);
        intLabel->setObjectName(QString::fromUtf8("intLabel"));
        intLabel->setFont(font);
        intLabel->setAlignment(Qt::AlignCenter);

        abilityScoresLayout->addWidget(intLabel);

        wisLabel = new QLabel(MonsterManual);
        wisLabel->setObjectName(QString::fromUtf8("wisLabel"));
        wisLabel->setFont(font);
        wisLabel->setAlignment(Qt::AlignCenter);

        abilityScoresLayout->addWidget(wisLabel);

        chaLabel = new QLabel(MonsterManual);
        chaLabel->setObjectName(QString::fromUtf8("chaLabel"));
        chaLabel->setFont(font);
        chaLabel->setAlignment(Qt::AlignCenter);

        abilityScoresLayout->addWidget(chaLabel);


        dataLayout->addLayout(abilityScoresLayout);

        abilitiesScrollArea = new QScrollArea(MonsterManual);
        abilitiesScrollArea->setObjectName(QString::fromUtf8("abilitiesScrollArea"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(abilitiesScrollArea->sizePolicy().hasHeightForWidth());
        abilitiesScrollArea->setSizePolicy(sizePolicy4);
        abilitiesScrollArea->setFont(font);
        abilitiesScrollArea->setLayoutDirection(Qt::LeftToRight);
        abilitiesScrollArea->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        abilitiesScrollArea->setFrameShape(QFrame::NoFrame);
        abilitiesScrollArea->setFrameShadow(QFrame::Plain);
        abilitiesScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        abilitiesScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        abilitiesScrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        abilitiesScrollArea->setWidgetResizable(true);
        abilitiesScrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        abilitiesContents = new QWidget();
        abilitiesContents->setObjectName(QString::fromUtf8("abilitiesContents"));
        abilitiesContents->setGeometry(QRect(0, 0, 732, 439));
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(abilitiesContents->sizePolicy().hasHeightForWidth());
        abilitiesContents->setSizePolicy(sizePolicy5);
        verticalLayout = new QVBoxLayout(abilitiesContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        abilitiesLabel = new QLabel(abilitiesContents);
        abilitiesLabel->setObjectName(QString::fromUtf8("abilitiesLabel"));
        abilitiesLabel->setFont(font);
        abilitiesLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        abilitiesLabel->setWordWrap(true);

        verticalLayout->addWidget(abilitiesLabel);

        abilitiesScrollArea->setWidget(abilitiesContents);

        dataLayout->addWidget(abilitiesScrollArea);

        dataLayout->setStretch(0, 1);
        dataLayout->setStretch(1, 1);
        dataLayout->setStretch(2, 6);
        dataLayout->setStretch(3, 2);
        dataLayout->setStretch(4, 10);

        horizontalLayout->addLayout(dataLayout);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 7);

        retranslateUi(MonsterManual);

        QMetaObject::connectSlotsByName(MonsterManual);
    } // setupUi

    void retranslateUi(QWidget *MonsterManual)
    {
        MonsterManual->setWindowTitle(QCoreApplication::translate("MonsterManual", "Form", nullptr));
        sortLabel->setText(QCoreApplication::translate("MonsterManual", "Sort Field", nullptr));
        searchBar->setPlaceholderText(QCoreApplication::translate("MonsterManual", "Search", nullptr));
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
