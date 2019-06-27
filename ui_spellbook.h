/********************************************************************************
** Form generated from reading UI file 'spellbook.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPELLBOOK_H
#define UI_SPELLBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Spellbook
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *leftLayout;
    QGridLayout *sortFilterLayout;
    QLabel *sort2Label;
    QComboBox *sort1Box;
    QLabel *filterLabel;
    QLabel *sort1Label;
    QComboBox *sort2Box;
    QComboBox *filterBox;
    QHBoxLayout *favoritesSearchLayout;
    QRadioButton *favoritesButton;
    QLineEdit *searchBar;
    QHBoxLayout *sourcebooksLayout;
    QCheckBox *phbCheckbox;
    QCheckBox *scagCheckbox;
    QCheckBox *xgeCheckbox;
    QTableWidget *spellList;
    QVBoxLayout *rightLayout;
    QHBoxLayout *nameFavoritesLayout;
    QLabel *nameLabel;
    QPushButton *favButton;
    QLabel *levelLabel;
    QLabel *rangeLabel;
    QLabel *concentrationLabel;
    QLabel *schoolLabel;
    QLabel *ritualLabel;
    QLabel *durationLabel;
    QLabel *castingTimeLabel;
    QLabel *componentsLabel;
    QLabel *pageLabel;
    QLabel *materialLabel;
    QLabel *classesLabel;
    QLabel *descriptionTitle;
    QScrollArea *descScrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QLabel *descriptionLabel;
    QLabel *higherLevelTitle;
    QLabel *higherLevelLabel;

    void setupUi(QWidget *Spellbook)
    {
        if (Spellbook->objectName().isEmpty())
            Spellbook->setObjectName(QStringLiteral("Spellbook"));
        Spellbook->resize(1343, 829);
        Spellbook->setAutoFillBackground(false);
        Spellbook->setStyleSheet(QStringLiteral("background-color: transparent"));
        horizontalLayout = new QHBoxLayout(Spellbook);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        leftLayout = new QVBoxLayout();
        leftLayout->setObjectName(QStringLiteral("leftLayout"));
        sortFilterLayout = new QGridLayout();
        sortFilterLayout->setObjectName(QStringLiteral("sortFilterLayout"));
        sort2Label = new QLabel(Spellbook);
        sort2Label->setObjectName(QStringLiteral("sort2Label"));

        sortFilterLayout->addWidget(sort2Label, 0, 1, 1, 1);

        sort1Box = new QComboBox(Spellbook);
        sort1Box->setObjectName(QStringLiteral("sort1Box"));
        sort1Box->setStyleSheet(QStringLiteral(""));

        sortFilterLayout->addWidget(sort1Box, 1, 0, 1, 1);

        filterLabel = new QLabel(Spellbook);
        filterLabel->setObjectName(QStringLiteral("filterLabel"));

        sortFilterLayout->addWidget(filterLabel, 0, 2, 1, 1);

        sort1Label = new QLabel(Spellbook);
        sort1Label->setObjectName(QStringLiteral("sort1Label"));

        sortFilterLayout->addWidget(sort1Label, 0, 0, 1, 1);

        sort2Box = new QComboBox(Spellbook);
        sort2Box->setObjectName(QStringLiteral("sort2Box"));
        sort2Box->setStyleSheet(QStringLiteral(""));

        sortFilterLayout->addWidget(sort2Box, 1, 1, 1, 1);

        filterBox = new QComboBox(Spellbook);
        filterBox->setObjectName(QStringLiteral("filterBox"));
        filterBox->setStyleSheet(QStringLiteral(""));

        sortFilterLayout->addWidget(filterBox, 1, 2, 1, 1);


        leftLayout->addLayout(sortFilterLayout);

        favoritesSearchLayout = new QHBoxLayout();
        favoritesSearchLayout->setObjectName(QStringLiteral("favoritesSearchLayout"));
        favoritesButton = new QRadioButton(Spellbook);
        favoritesButton->setObjectName(QStringLiteral("favoritesButton"));

        favoritesSearchLayout->addWidget(favoritesButton);

        searchBar = new QLineEdit(Spellbook);
        searchBar->setObjectName(QStringLiteral("searchBar"));
        searchBar->setFocusPolicy(Qt::ClickFocus);
        searchBar->setAutoFillBackground(false);

        favoritesSearchLayout->addWidget(searchBar);


        leftLayout->addLayout(favoritesSearchLayout);

        sourcebooksLayout = new QHBoxLayout();
        sourcebooksLayout->setObjectName(QStringLiteral("sourcebooksLayout"));
        sourcebooksLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        sourcebooksLayout->setContentsMargins(0, 0, 0, -1);
        phbCheckbox = new QCheckBox(Spellbook);
        phbCheckbox->setObjectName(QStringLiteral("phbCheckbox"));
        phbCheckbox->setChecked(true);

        sourcebooksLayout->addWidget(phbCheckbox);

        scagCheckbox = new QCheckBox(Spellbook);
        scagCheckbox->setObjectName(QStringLiteral("scagCheckbox"));

        sourcebooksLayout->addWidget(scagCheckbox);

        xgeCheckbox = new QCheckBox(Spellbook);
        xgeCheckbox->setObjectName(QStringLiteral("xgeCheckbox"));

        sourcebooksLayout->addWidget(xgeCheckbox);

        sourcebooksLayout->setStretch(0, 1);
        sourcebooksLayout->setStretch(1, 1);
        sourcebooksLayout->setStretch(2, 1);

        leftLayout->addLayout(sourcebooksLayout);

        spellList = new QTableWidget(Spellbook);
        if (spellList->columnCount() < 3)
            spellList->setColumnCount(3);
        if (spellList->rowCount() < 6)
            spellList->setRowCount(6);
        spellList->setObjectName(QStringLiteral("spellList"));
        spellList->setLineWidth(1);
        spellList->setShowGrid(false);
        spellList->setGridStyle(Qt::NoPen);
        spellList->setSortingEnabled(false);
        spellList->setRowCount(6);
        spellList->setColumnCount(3);
        spellList->horizontalHeader()->setVisible(false);
        spellList->horizontalHeader()->setDefaultSectionSize(175);
        spellList->horizontalHeader()->setHighlightSections(false);
        spellList->horizontalHeader()->setStretchLastSection(true);
        spellList->verticalHeader()->setVisible(false);
        spellList->verticalHeader()->setHighlightSections(false);

        leftLayout->addWidget(spellList);


        horizontalLayout->addLayout(leftLayout);

        rightLayout = new QVBoxLayout();
        rightLayout->setSpacing(5);
        rightLayout->setObjectName(QStringLiteral("rightLayout"));
        rightLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        rightLayout->setContentsMargins(25, -1, -1, -1);
        nameFavoritesLayout = new QHBoxLayout();
        nameFavoritesLayout->setObjectName(QStringLiteral("nameFavoritesLayout"));
        nameLabel = new QLabel(Spellbook);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        QFont font;
        font.setFamily(QStringLiteral("URW Chancery L"));
        font.setPointSize(30);
        font.setItalic(true);
        nameLabel->setFont(font);
        nameLabel->setAlignment(Qt::AlignCenter);

        nameFavoritesLayout->addWidget(nameLabel);

        favButton = new QPushButton(Spellbook);
        favButton->setObjectName(QStringLiteral("favButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(favButton->sizePolicy().hasHeightForWidth());
        favButton->setSizePolicy(sizePolicy);
        favButton->setFocusPolicy(Qt::NoFocus);
        favButton->setAutoFillBackground(false);
        favButton->setStyleSheet(QStringLiteral(""));
        favButton->setCheckable(false);

        nameFavoritesLayout->addWidget(favButton);


        rightLayout->addLayout(nameFavoritesLayout);

        levelLabel = new QLabel(Spellbook);
        levelLabel->setObjectName(QStringLiteral("levelLabel"));

        rightLayout->addWidget(levelLabel);

        rangeLabel = new QLabel(Spellbook);
        rangeLabel->setObjectName(QStringLiteral("rangeLabel"));
        rangeLabel->setTextFormat(Qt::AutoText);

        rightLayout->addWidget(rangeLabel);

        concentrationLabel = new QLabel(Spellbook);
        concentrationLabel->setObjectName(QStringLiteral("concentrationLabel"));

        rightLayout->addWidget(concentrationLabel);

        schoolLabel = new QLabel(Spellbook);
        schoolLabel->setObjectName(QStringLiteral("schoolLabel"));

        rightLayout->addWidget(schoolLabel);

        ritualLabel = new QLabel(Spellbook);
        ritualLabel->setObjectName(QStringLiteral("ritualLabel"));

        rightLayout->addWidget(ritualLabel);

        durationLabel = new QLabel(Spellbook);
        durationLabel->setObjectName(QStringLiteral("durationLabel"));

        rightLayout->addWidget(durationLabel);

        castingTimeLabel = new QLabel(Spellbook);
        castingTimeLabel->setObjectName(QStringLiteral("castingTimeLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(castingTimeLabel->sizePolicy().hasHeightForWidth());
        castingTimeLabel->setSizePolicy(sizePolicy1);

        rightLayout->addWidget(castingTimeLabel);

        componentsLabel = new QLabel(Spellbook);
        componentsLabel->setObjectName(QStringLiteral("componentsLabel"));
        sizePolicy1.setHeightForWidth(componentsLabel->sizePolicy().hasHeightForWidth());
        componentsLabel->setSizePolicy(sizePolicy1);

        rightLayout->addWidget(componentsLabel);

        pageLabel = new QLabel(Spellbook);
        pageLabel->setObjectName(QStringLiteral("pageLabel"));

        rightLayout->addWidget(pageLabel);

        materialLabel = new QLabel(Spellbook);
        materialLabel->setObjectName(QStringLiteral("materialLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(materialLabel->sizePolicy().hasHeightForWidth());
        materialLabel->setSizePolicy(sizePolicy2);
        materialLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        materialLabel->setWordWrap(true);

        rightLayout->addWidget(materialLabel);

        classesLabel = new QLabel(Spellbook);
        classesLabel->setObjectName(QStringLiteral("classesLabel"));
        sizePolicy1.setHeightForWidth(classesLabel->sizePolicy().hasHeightForWidth());
        classesLabel->setSizePolicy(sizePolicy1);

        rightLayout->addWidget(classesLabel);

        descriptionTitle = new QLabel(Spellbook);
        descriptionTitle->setObjectName(QStringLiteral("descriptionTitle"));

        rightLayout->addWidget(descriptionTitle);

        descScrollArea = new QScrollArea(Spellbook);
        descScrollArea->setObjectName(QStringLiteral("descScrollArea"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(descScrollArea->sizePolicy().hasHeightForWidth());
        descScrollArea->setSizePolicy(sizePolicy3);
        descScrollArea->setAutoFillBackground(true);
        descScrollArea->setStyleSheet(QStringLiteral("background-color: transparent"));
        descScrollArea->setFrameShape(QFrame::NoFrame);
        descScrollArea->setFrameShadow(QFrame::Plain);
        descScrollArea->setLineWidth(0);
        descScrollArea->setWidgetResizable(true);
        descScrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 798, 523));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy4);
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(8);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, -1, -1);
        descriptionLabel = new QLabel(scrollAreaWidgetContents);
        descriptionLabel->setObjectName(QStringLiteral("descriptionLabel"));
        sizePolicy2.setHeightForWidth(descriptionLabel->sizePolicy().hasHeightForWidth());
        descriptionLabel->setSizePolicy(sizePolicy2);
        descriptionLabel->setTextFormat(Qt::AutoText);
        descriptionLabel->setScaledContents(false);
        descriptionLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        descriptionLabel->setWordWrap(true);

        verticalLayout->addWidget(descriptionLabel);

        higherLevelTitle = new QLabel(scrollAreaWidgetContents);
        higherLevelTitle->setObjectName(QStringLiteral("higherLevelTitle"));
        sizePolicy2.setHeightForWidth(higherLevelTitle->sizePolicy().hasHeightForWidth());
        higherLevelTitle->setSizePolicy(sizePolicy2);
        higherLevelTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(higherLevelTitle);

        higherLevelLabel = new QLabel(scrollAreaWidgetContents);
        higherLevelLabel->setObjectName(QStringLiteral("higherLevelLabel"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(higherLevelLabel->sizePolicy().hasHeightForWidth());
        higherLevelLabel->setSizePolicy(sizePolicy5);
        higherLevelLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        higherLevelLabel->setWordWrap(true);

        verticalLayout->addWidget(higherLevelLabel);

        descScrollArea->setWidget(scrollAreaWidgetContents);

        rightLayout->addWidget(descScrollArea);


        horizontalLayout->addLayout(rightLayout);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 5);

        retranslateUi(Spellbook);

        QMetaObject::connectSlotsByName(Spellbook);
    } // setupUi

    void retranslateUi(QWidget *Spellbook)
    {
        Spellbook->setWindowTitle(QApplication::translate("Spellbook", "Form", 0));
        sort2Label->setText(QApplication::translate("Spellbook", "Sort field 2", 0));
        filterLabel->setText(QApplication::translate("Spellbook", "Filter by class", 0));
        sort1Label->setText(QApplication::translate("Spellbook", "Sort field 1", 0));
        favoritesButton->setText(QApplication::translate("Spellbook", "Favorites", 0));
        searchBar->setText(QString());
        searchBar->setPlaceholderText(QApplication::translate("Spellbook", "Search", 0));
        phbCheckbox->setText(QApplication::translate("Spellbook", "Player's Handbook", 0));
        scagCheckbox->setText(QApplication::translate("Spellbook", "Sword Coast AG", 0));
        xgeCheckbox->setText(QApplication::translate("Spellbook", "Xanathar's GTE", 0));
        nameLabel->setText(QString());
        favButton->setText(QString());
        levelLabel->setText(QString());
        rangeLabel->setText(QString());
        concentrationLabel->setText(QString());
        schoolLabel->setText(QString());
        ritualLabel->setText(QString());
        durationLabel->setText(QString());
        castingTimeLabel->setText(QString());
        componentsLabel->setText(QString());
        pageLabel->setText(QString());
        materialLabel->setText(QString());
        classesLabel->setText(QString());
        descriptionTitle->setText(QString());
        descriptionLabel->setText(QString());
        higherLevelTitle->setText(QString());
        higherLevelLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Spellbook: public Ui_Spellbook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPELLBOOK_H
