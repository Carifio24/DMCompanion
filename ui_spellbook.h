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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Spellbook
{
public:
    QLabel *nameLabel;
    QLabel *descriptionTitle;
    QLabel *subclassesLabel;
    QComboBox *sort1Box;
    QLabel *classesLabel;
    QTableWidget *spellList;
    QLabel *componentsLabel;
    QRadioButton *favoritesButton;
    QLabel *descriptionLabel;
    QLabel *castingTimeLabel;
    QLabel *materialLabel;
    QComboBox *sort2Box;
    QLabel *concentrationLabel;
    QLabel *schoolLabel;
    QLabel *sort1Label;
    QComboBox *filterBox;
    QLabel *levelLabel;
    QLineEdit *searchBar;
    QLabel *ritualLabel;
    QScrollArea *descScrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *favButton;
    QLabel *rangeLabel;
    QLabel *filterLabel;
    QLabel *pageLabel;
    QLabel *durationLabel;
    QLabel *sort2Label;
    QCheckBox *phbCheckbox;
    QCheckBox *xgeCheckbox;
    QCheckBox *scagCheckbox;

    void setupUi(QWidget *Spellbook)
    {
        if (Spellbook->objectName().isEmpty())
            Spellbook->setObjectName(QStringLiteral("Spellbook"));
        Spellbook->resize(1343, 829);
        nameLabel = new QLabel(Spellbook);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(529, 49, 591, 71));
        QFont font;
        font.setFamily(QStringLiteral("URW Chancery L"));
        font.setPointSize(30);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(7);
        nameLabel->setFont(font);
        nameLabel->setStyleSheet(QLatin1String("font: 30pt \"Vivaldi\";\n"
"font: 57 italic 30pt \"URW Chancery L\";"));
        nameLabel->setAlignment(Qt::AlignCenter);
        descriptionTitle = new QLabel(Spellbook);
        descriptionTitle->setObjectName(QStringLiteral("descriptionTitle"));
        descriptionTitle->setGeometry(QRect(550, 440, 111, 20));
        subclassesLabel = new QLabel(Spellbook);
        subclassesLabel->setObjectName(QStringLiteral("subclassesLabel"));
        subclassesLabel->setGeometry(QRect(550, 410, 451, 17));
        sort1Box = new QComboBox(Spellbook);
        sort1Box->setObjectName(QStringLiteral("sort1Box"));
        sort1Box->setGeometry(QRect(30, 49, 111, 25));
        classesLabel = new QLabel(Spellbook);
        classesLabel->setObjectName(QStringLiteral("classesLabel"));
        classesLabel->setGeometry(QRect(550, 380, 451, 17));
        spellList = new QTableWidget(Spellbook);
        spellList->setObjectName(QStringLiteral("spellList"));
        spellList->setGeometry(QRect(20, 140, 431, 671));
        spellList->setLineWidth(1);
        spellList->setShowGrid(false);
        spellList->setGridStyle(Qt::NoPen);
        spellList->setSortingEnabled(false);
        spellList->horizontalHeader()->setVisible(false);
        spellList->horizontalHeader()->setDefaultSectionSize(175);
        spellList->horizontalHeader()->setHighlightSections(false);
        spellList->horizontalHeader()->setStretchLastSection(true);
        spellList->verticalHeader()->setVisible(false);
        spellList->verticalHeader()->setHighlightSections(false);
        componentsLabel = new QLabel(Spellbook);
        componentsLabel->setObjectName(QStringLiteral("componentsLabel"));
        componentsLabel->setGeometry(QRect(550, 290, 181, 16));
        favoritesButton = new QRadioButton(Spellbook);
        favoritesButton->setObjectName(QStringLiteral("favoritesButton"));
        favoritesButton->setGeometry(QRect(30, 79, 112, 23));
        descriptionLabel = new QLabel(Spellbook);
        descriptionLabel->setObjectName(QStringLiteral("descriptionLabel"));
        descriptionLabel->setGeometry(QRect(550, 470, 591, 301));
        descriptionLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        descriptionLabel->setWordWrap(true);
        castingTimeLabel = new QLabel(Spellbook);
        castingTimeLabel->setObjectName(QStringLiteral("castingTimeLabel"));
        castingTimeLabel->setGeometry(QRect(550, 169, 241, 21));
        materialLabel = new QLabel(Spellbook);
        materialLabel->setObjectName(QStringLiteral("materialLabel"));
        materialLabel->setGeometry(QRect(550, 320, 641, 51));
        materialLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        materialLabel->setWordWrap(true);
        sort2Box = new QComboBox(Spellbook);
        sort2Box->setObjectName(QStringLiteral("sort2Box"));
        sort2Box->setGeometry(QRect(180, 49, 111, 25));
        concentrationLabel = new QLabel(Spellbook);
        concentrationLabel->setObjectName(QStringLiteral("concentrationLabel"));
        concentrationLabel->setGeometry(QRect(550, 230, 141, 17));
        schoolLabel = new QLabel(Spellbook);
        schoolLabel->setObjectName(QStringLiteral("schoolLabel"));
        schoolLabel->setGeometry(QRect(550, 135, 201, 21));
        sort1Label = new QLabel(Spellbook);
        sort1Label->setObjectName(QStringLiteral("sort1Label"));
        sort1Label->setGeometry(QRect(30, 19, 81, 17));
        filterBox = new QComboBox(Spellbook);
        filterBox->setObjectName(QStringLiteral("filterBox"));
        filterBox->setGeometry(QRect(340, 49, 101, 25));
        levelLabel = new QLabel(Spellbook);
        levelLabel->setObjectName(QStringLiteral("levelLabel"));
        levelLabel->setGeometry(QRect(780, 136, 121, 20));
        searchBar = new QLineEdit(Spellbook);
        searchBar->setObjectName(QStringLiteral("searchBar"));
        searchBar->setGeometry(QRect(140, 79, 311, 25));
        searchBar->setFocusPolicy(Qt::ClickFocus);
        searchBar->setAutoFillBackground(true);
        ritualLabel = new QLabel(Spellbook);
        ritualLabel->setObjectName(QStringLiteral("ritualLabel"));
        ritualLabel->setGeometry(QRect(790, 227, 171, 20));
        descScrollArea = new QScrollArea(Spellbook);
        descScrollArea->setObjectName(QStringLiteral("descScrollArea"));
        descScrollArea->setGeometry(QRect(550, 470, 591, 321));
        descScrollArea->setFrameShape(QFrame::NoFrame);
        descScrollArea->setLineWidth(0);
        descScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 591, 321));
        descScrollArea->setWidget(scrollAreaWidgetContents);
        favButton = new QPushButton(Spellbook);
        favButton->setObjectName(QStringLiteral("favButton"));
        favButton->setGeometry(QRect(1130, 49, 71, 71));
        favButton->setFocusPolicy(Qt::NoFocus);
        rangeLabel = new QLabel(Spellbook);
        rangeLabel->setObjectName(QStringLiteral("rangeLabel"));
        rangeLabel->setGeometry(QRect(550, 200, 211, 17));
        rangeLabel->setTextFormat(Qt::AutoText);
        filterLabel = new QLabel(Spellbook);
        filterLabel->setObjectName(QStringLiteral("filterLabel"));
        filterLabel->setGeometry(QRect(340, 19, 101, 17));
        pageLabel = new QLabel(Spellbook);
        pageLabel->setObjectName(QStringLiteral("pageLabel"));
        pageLabel->setGeometry(QRect(980, 139, 171, 17));
        durationLabel = new QLabel(Spellbook);
        durationLabel->setObjectName(QStringLiteral("durationLabel"));
        durationLabel->setGeometry(QRect(550, 260, 281, 17));
        sort2Label = new QLabel(Spellbook);
        sort2Label->setObjectName(QStringLiteral("sort2Label"));
        sort2Label->setGeometry(QRect(190, 19, 81, 17));
        phbCheckbox = new QCheckBox(Spellbook);
        phbCheckbox->setObjectName(QStringLiteral("phbCheckbox"));
        phbCheckbox->setGeometry(QRect(20, 110, 141, 20));
        phbCheckbox->setChecked(true);
        xgeCheckbox = new QCheckBox(Spellbook);
        xgeCheckbox->setObjectName(QStringLiteral("xgeCheckbox"));
        xgeCheckbox->setGeometry(QRect(180, 110, 121, 20));
        scagCheckbox = new QCheckBox(Spellbook);
        scagCheckbox->setObjectName(QStringLiteral("scagCheckbox"));
        scagCheckbox->setGeometry(QRect(320, 110, 161, 20));

        retranslateUi(Spellbook);

        QMetaObject::connectSlotsByName(Spellbook);
    } // setupUi

    void retranslateUi(QWidget *Spellbook)
    {
        Spellbook->setWindowTitle(QApplication::translate("Spellbook", "Form", 0));
        nameLabel->setText(QString());
        descriptionTitle->setText(QString());
        subclassesLabel->setText(QString());
        classesLabel->setText(QString());
        componentsLabel->setText(QString());
        favoritesButton->setText(QApplication::translate("Spellbook", "Favorites", 0));
        descriptionLabel->setText(QString());
        castingTimeLabel->setText(QString());
        materialLabel->setText(QString());
        concentrationLabel->setText(QString());
        schoolLabel->setText(QString());
        sort1Label->setText(QApplication::translate("Spellbook", "Sort field 1", 0));
        levelLabel->setText(QString());
        searchBar->setText(QString());
        searchBar->setPlaceholderText(QApplication::translate("Spellbook", "Search", 0));
        ritualLabel->setText(QString());
        favButton->setText(QString());
        rangeLabel->setText(QString());
        filterLabel->setText(QApplication::translate("Spellbook", "Filter by class", 0));
        pageLabel->setText(QString());
        durationLabel->setText(QString());
        sort2Label->setText(QApplication::translate("Spellbook", "Sort field 2", 0));
        phbCheckbox->setText(QApplication::translate("Spellbook", "Player's Handbook", 0));
        xgeCheckbox->setText(QApplication::translate("Spellbook", "Xanathar's GTE", 0));
        scagCheckbox->setText(QApplication::translate("Spellbook", "Sword Coast AG", 0));
    } // retranslateUi

};

namespace Ui {
    class Spellbook: public Ui_Spellbook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPELLBOOK_H
