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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
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
    QGridLayout *gridLayout;
    QComboBox *sortComboBox;
    QLabel *sortLabel;
    QPushButton *sortReverse;
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
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        sortComboBox = new QComboBox(MonsterManual);
        sortComboBox->setObjectName(QString::fromUtf8("sortComboBox"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setBold(false);
        font1.setWeight(50);
        sortComboBox->setFont(font1);
        sortComboBox->setStyleSheet(QString::fromUtf8("background-color : rgb(231,208,166)"));

        gridLayout->addWidget(sortComboBox, 1, 0, 1, 1);

        sortLabel = new QLabel(MonsterManual);
        sortLabel->setObjectName(QString::fromUtf8("sortLabel"));
        sortLabel->setFont(font);

        gridLayout->addWidget(sortLabel, 0, 0, 1, 1);

        sortReverse = new QPushButton(MonsterManual);
        sortReverse->setObjectName(QString::fromUtf8("sortReverse"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sortReverse->sizePolicy().hasHeightForWidth());
        sortReverse->setSizePolicy(sizePolicy);
        sortReverse->setStyleSheet(QString::fromUtf8("background: none; border: none;"));

        gridLayout->addWidget(sortReverse, 1, 1, 1, 1);

        gridLayout->setColumnStretch(0, 4);
        gridLayout->setColumnStretch(1, 1);

        leftLayout->addLayout(gridLayout);

        searchBar = new QLineEdit(MonsterManual);
        searchBar->setObjectName(QString::fromUtf8("searchBar"));
        searchBar->setFont(font);
        searchBar->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"background: transparent\n"
""));

        leftLayout->addWidget(searchBar);

        monsterTable = new QTableWidget(MonsterManual);
        monsterTable->setObjectName(QString::fromUtf8("monsterTable"));
        monsterTable->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(monsterTable->sizePolicy().hasHeightForWidth());
        monsterTable->setSizePolicy(sizePolicy1);
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
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(30);
        font2.setItalic(true);
        nameLabel->setFont(font2);
        nameLabel->setAlignment(Qt::AlignCenter);

        dataLayout->addWidget(nameLabel);

        sizeTypeLabel = new QLabel(MonsterManual);
        sizeTypeLabel->setObjectName(QString::fromUtf8("sizeTypeLabel"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setItalic(true);
        font3.setWeight(50);
        sizeTypeLabel->setFont(font3);
        sizeTypeLabel->setStyleSheet(QString::fromUtf8("font : italic"));
        sizeTypeLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        dataLayout->addWidget(sizeTypeLabel);

        statsImageLayout = new QHBoxLayout();
        statsImageLayout->setObjectName(QString::fromUtf8("statsImageLayout"));
        statsLayout = new QVBoxLayout();
        statsLayout->setObjectName(QString::fromUtf8("statsLayout"));
        acLabel = new QLabel(MonsterManual);
        acLabel->setObjectName(QString::fromUtf8("acLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(acLabel->sizePolicy().hasHeightForWidth());
        acLabel->setSizePolicy(sizePolicy2);
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
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(savingThrowsLabel->sizePolicy().hasHeightForWidth());
        savingThrowsLabel->setSizePolicy(sizePolicy3);
        savingThrowsLabel->setFont(font);
        savingThrowsLabel->setWordWrap(true);

        statsLayout->addWidget(savingThrowsLabel);

        sensesLabel = new QLabel(MonsterManual);
        sensesLabel->setObjectName(QString::fromUtf8("sensesLabel"));
        sizePolicy3.setHeightForWidth(sensesLabel->sizePolicy().hasHeightForWidth());
        sensesLabel->setSizePolicy(sizePolicy3);
        sensesLabel->setFont(font);
        sensesLabel->setWordWrap(true);

        statsLayout->addWidget(sensesLabel);

        damageImmunitiesLabel = new QLabel(MonsterManual);
        damageImmunitiesLabel->setObjectName(QString::fromUtf8("damageImmunitiesLabel"));
        sizePolicy3.setHeightForWidth(damageImmunitiesLabel->sizePolicy().hasHeightForWidth());
        damageImmunitiesLabel->setSizePolicy(sizePolicy3);
        damageImmunitiesLabel->setFont(font);
        damageImmunitiesLabel->setWordWrap(true);

        statsLayout->addWidget(damageImmunitiesLabel);

        languagesLabel = new QLabel(MonsterManual);
        languagesLabel->setObjectName(QString::fromUtf8("languagesLabel"));
        sizePolicy3.setHeightForWidth(languagesLabel->sizePolicy().hasHeightForWidth());
        languagesLabel->setSizePolicy(sizePolicy3);
        languagesLabel->setFont(font);
        languagesLabel->setWordWrap(true);

        statsLayout->addWidget(languagesLabel);

        conditionImmunitiesLabel = new QLabel(MonsterManual);
        conditionImmunitiesLabel->setObjectName(QString::fromUtf8("conditionImmunitiesLabel"));
        sizePolicy3.setHeightForWidth(conditionImmunitiesLabel->sizePolicy().hasHeightForWidth());
        conditionImmunitiesLabel->setSizePolicy(sizePolicy3);
        conditionImmunitiesLabel->setFont(font);
        conditionImmunitiesLabel->setWordWrap(true);

        statsLayout->addWidget(conditionImmunitiesLabel);

        challengeRatingLabel = new QLabel(MonsterManual);
        challengeRatingLabel->setObjectName(QString::fromUtf8("challengeRatingLabel"));
        sizePolicy3.setHeightForWidth(challengeRatingLabel->sizePolicy().hasHeightForWidth());
        challengeRatingLabel->setSizePolicy(sizePolicy3);
        challengeRatingLabel->setFont(font);
        challengeRatingLabel->setWordWrap(true);

        statsLayout->addWidget(challengeRatingLabel);

        damageResistancesLabel = new QLabel(MonsterManual);
        damageResistancesLabel->setObjectName(QString::fromUtf8("damageResistancesLabel"));
        sizePolicy3.setHeightForWidth(damageResistancesLabel->sizePolicy().hasHeightForWidth());
        damageResistancesLabel->setSizePolicy(sizePolicy3);
        damageResistancesLabel->setFont(font);
        damageResistancesLabel->setWordWrap(true);

        statsLayout->addWidget(damageResistancesLabel);

        damageVulnerabilitiesLabel = new QLabel(MonsterManual);
        damageVulnerabilitiesLabel->setObjectName(QString::fromUtf8("damageVulnerabilitiesLabel"));
        sizePolicy3.setHeightForWidth(damageVulnerabilitiesLabel->sizePolicy().hasHeightForWidth());
        damageVulnerabilitiesLabel->setSizePolicy(sizePolicy3);
        damageVulnerabilitiesLabel->setFont(font);
        damageVulnerabilitiesLabel->setWordWrap(true);

        statsLayout->addWidget(damageVulnerabilitiesLabel);

        skillsLabel = new QLabel(MonsterManual);
        skillsLabel->setObjectName(QString::fromUtf8("skillsLabel"));
        sizePolicy3.setHeightForWidth(skillsLabel->sizePolicy().hasHeightForWidth());
        skillsLabel->setSizePolicy(sizePolicy3);
        skillsLabel->setFont(font);
        skillsLabel->setWordWrap(true);

        statsLayout->addWidget(skillsLabel);


        statsImageLayout->addLayout(statsLayout);

        imageLabel = new QLabel(MonsterManual);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy4);
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
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(abilitiesScrollArea->sizePolicy().hasHeightForWidth());
        abilitiesScrollArea->setSizePolicy(sizePolicy5);
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
        QSizePolicy sizePolicy6(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(abilitiesContents->sizePolicy().hasHeightForWidth());
        abilitiesContents->setSizePolicy(sizePolicy6);
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
        MonsterManual->setWindowTitle(QApplication::translate("MonsterManual", "Form", nullptr));
        sortLabel->setText(QApplication::translate("MonsterManual", "Sort Field", nullptr));
        sortReverse->setText(QString());
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
