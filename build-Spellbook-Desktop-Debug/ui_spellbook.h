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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Spellbook
{
public:
    QWidget *centralWidget;
    QTableWidget *spellList;
    QLabel *nameLabel;
    QLabel *schoolLabel;
    QLabel *rangeLabel;
    QLabel *concentrationLabel;
    QLabel *ritualLabel;
    QLabel *durationLabel;
    QLabel *componentsLabel;
    QLabel *materialLabel;
    QLabel *levelLabel;
    QLabel *descriptionLabel;
    QComboBox *sort1Box;
    QLabel *sort1Label;
    QComboBox *sort2Box;
    QLabel *sort2Label;
    QLabel *classesLabel;
    QLabel *subclassesLabel;
    QLabel *filterLabel;
    QComboBox *filterBox;
    QScrollArea *descScrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *descriptionTitle;
    QLabel *castingTimeLabel;
    QLabel *pageLabel;
    QRadioButton *favoritesButton;
    QPushButton *favButton;
    QLineEdit *searchBar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Spellbook)
    {
        if (Spellbook->objectName().isEmpty())
            Spellbook->setObjectName(QStringLiteral("Spellbook"));
        Spellbook->resize(1225, 852);
        centralWidget = new QWidget(Spellbook);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        spellList = new QTableWidget(centralWidget);
        spellList->setObjectName(QStringLiteral("spellList"));
        spellList->setGeometry(QRect(50, 120, 431, 671));
        spellList->setLineWidth(1);
        spellList->setShowGrid(false);
        spellList->setGridStyle(Qt::NoPen);
        spellList->horizontalHeader()->setVisible(false);
        spellList->horizontalHeader()->setDefaultSectionSize(175);
        spellList->horizontalHeader()->setHighlightSections(false);
        spellList->horizontalHeader()->setStretchLastSection(true);
        spellList->verticalHeader()->setVisible(false);
        spellList->verticalHeader()->setHighlightSections(false);
        nameLabel = new QLabel(centralWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(539, 50, 591, 71));
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
        schoolLabel = new QLabel(centralWidget);
        schoolLabel->setObjectName(QStringLiteral("schoolLabel"));
        schoolLabel->setGeometry(QRect(560, 136, 201, 21));
        rangeLabel = new QLabel(centralWidget);
        rangeLabel->setObjectName(QStringLiteral("rangeLabel"));
        rangeLabel->setGeometry(QRect(560, 201, 211, 17));
        rangeLabel->setTextFormat(Qt::AutoText);
        concentrationLabel = new QLabel(centralWidget);
        concentrationLabel->setObjectName(QStringLiteral("concentrationLabel"));
        concentrationLabel->setGeometry(QRect(560, 231, 141, 17));
        ritualLabel = new QLabel(centralWidget);
        ritualLabel->setObjectName(QStringLiteral("ritualLabel"));
        ritualLabel->setGeometry(QRect(800, 228, 171, 20));
        durationLabel = new QLabel(centralWidget);
        durationLabel->setObjectName(QStringLiteral("durationLabel"));
        durationLabel->setGeometry(QRect(560, 261, 281, 17));
        componentsLabel = new QLabel(centralWidget);
        componentsLabel->setObjectName(QStringLiteral("componentsLabel"));
        componentsLabel->setGeometry(QRect(560, 291, 181, 16));
        materialLabel = new QLabel(centralWidget);
        materialLabel->setObjectName(QStringLiteral("materialLabel"));
        materialLabel->setGeometry(QRect(560, 321, 641, 51));
        materialLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        materialLabel->setWordWrap(true);
        levelLabel = new QLabel(centralWidget);
        levelLabel->setObjectName(QStringLiteral("levelLabel"));
        levelLabel->setGeometry(QRect(790, 137, 121, 20));
        descriptionLabel = new QLabel(centralWidget);
        descriptionLabel->setObjectName(QStringLiteral("descriptionLabel"));
        descriptionLabel->setGeometry(QRect(560, 471, 591, 301));
        descriptionLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        descriptionLabel->setWordWrap(true);
        sort1Box = new QComboBox(centralWidget);
        sort1Box->setObjectName(QStringLiteral("sort1Box"));
        sort1Box->setGeometry(QRect(60, 60, 111, 25));
        sort1Label = new QLabel(centralWidget);
        sort1Label->setObjectName(QStringLiteral("sort1Label"));
        sort1Label->setGeometry(QRect(60, 30, 81, 17));
        sort2Box = new QComboBox(centralWidget);
        sort2Box->setObjectName(QStringLiteral("sort2Box"));
        sort2Box->setGeometry(QRect(210, 60, 111, 25));
        sort2Label = new QLabel(centralWidget);
        sort2Label->setObjectName(QStringLiteral("sort2Label"));
        sort2Label->setGeometry(QRect(220, 30, 81, 17));
        classesLabel = new QLabel(centralWidget);
        classesLabel->setObjectName(QStringLiteral("classesLabel"));
        classesLabel->setGeometry(QRect(560, 381, 451, 17));
        subclassesLabel = new QLabel(centralWidget);
        subclassesLabel->setObjectName(QStringLiteral("subclassesLabel"));
        subclassesLabel->setGeometry(QRect(560, 411, 451, 17));
        filterLabel = new QLabel(centralWidget);
        filterLabel->setObjectName(QStringLiteral("filterLabel"));
        filterLabel->setGeometry(QRect(370, 30, 101, 17));
        filterBox = new QComboBox(centralWidget);
        filterBox->setObjectName(QStringLiteral("filterBox"));
        filterBox->setGeometry(QRect(370, 60, 101, 25));
        descScrollArea = new QScrollArea(centralWidget);
        descScrollArea->setObjectName(QStringLiteral("descScrollArea"));
        descScrollArea->setGeometry(QRect(560, 471, 591, 321));
        descScrollArea->setFrameShape(QFrame::NoFrame);
        descScrollArea->setLineWidth(0);
        descScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 591, 321));
        descScrollArea->setWidget(scrollAreaWidgetContents);
        descriptionTitle = new QLabel(centralWidget);
        descriptionTitle->setObjectName(QStringLiteral("descriptionTitle"));
        descriptionTitle->setGeometry(QRect(560, 441, 111, 20));
        castingTimeLabel = new QLabel(centralWidget);
        castingTimeLabel->setObjectName(QStringLiteral("castingTimeLabel"));
        castingTimeLabel->setGeometry(QRect(560, 170, 241, 21));
        pageLabel = new QLabel(centralWidget);
        pageLabel->setObjectName(QStringLiteral("pageLabel"));
        pageLabel->setGeometry(QRect(990, 140, 171, 17));
        favoritesButton = new QRadioButton(centralWidget);
        favoritesButton->setObjectName(QStringLiteral("favoritesButton"));
        favoritesButton->setGeometry(QRect(60, 90, 112, 23));
        favButton = new QPushButton(centralWidget);
        favButton->setObjectName(QStringLiteral("favButton"));
        favButton->setGeometry(QRect(1140, 50, 71, 71));
        favButton->setFocusPolicy(Qt::NoFocus);
        searchBar = new QLineEdit(centralWidget);
        searchBar->setObjectName(QStringLiteral("searchBar"));
        searchBar->setGeometry(QRect(170, 90, 311, 25));
        searchBar->setFocusPolicy(Qt::ClickFocus);
        searchBar->setAutoFillBackground(true);
        Spellbook->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Spellbook);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1225, 22));
        Spellbook->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Spellbook);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Spellbook->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Spellbook);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Spellbook->setStatusBar(statusBar);

        retranslateUi(Spellbook);

        QMetaObject::connectSlotsByName(Spellbook);
    } // setupUi

    void retranslateUi(QMainWindow *Spellbook)
    {
        Spellbook->setWindowTitle(QApplication::translate("Spellbook", "Spellbook", 0));
        nameLabel->setText(QString());
        schoolLabel->setText(QString());
        rangeLabel->setText(QString());
        concentrationLabel->setText(QString());
        ritualLabel->setText(QString());
        durationLabel->setText(QString());
        componentsLabel->setText(QString());
        materialLabel->setText(QString());
        levelLabel->setText(QString());
        descriptionLabel->setText(QString());
        sort1Label->setText(QApplication::translate("Spellbook", "Sort field 1", 0));
        sort2Label->setText(QApplication::translate("Spellbook", "Sort field 2", 0));
        classesLabel->setText(QString());
        subclassesLabel->setText(QString());
        filterLabel->setText(QApplication::translate("Spellbook", "Filter by class", 0));
        descriptionTitle->setText(QString());
        castingTimeLabel->setText(QString());
        pageLabel->setText(QString());
        favoritesButton->setText(QApplication::translate("Spellbook", "Favorites", 0));
        favButton->setText(QString());
        searchBar->setText(QString());
        searchBar->setPlaceholderText(QApplication::translate("Spellbook", "Search", 0));
    } // retranslateUi

};

namespace Ui {
    class Spellbook: public Ui_Spellbook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPELLBOOK_H
