#include "spellbook.h"
#include "ui_spellbook.h"
#include "spell_parse.h"
#include "sort.hpp"
#include "spell_sort_field.h"
#include "qdisplay.h"
#include "jsoncpp/json/json.h"
#include <boost/algorithm/string/predicate.hpp>
#include <QFile>
#include <QCheckBox>
#include <QStringView>
#include <QStringBuilder>
#include <QStandardItemModel>

#include <cmath>
#include <fstream>
#include <iostream>

#include "dnd/caster_class.h"
#include "dnd/spell.h"
#include "dnd/converters.h"
#include "dnd/duration.h"
#include "dnd/converters.h"
#include "dnd/string_helpers.h"

using namespace DnD;

Spellbook::Spellbook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Spellbook)
{
    using namespace DnD;

    ui->setupUi(this);

    // Set items to be transparent
//    setStyleSheet("background-color:transparent");
//    ui->descScrollArea->setStyleSheet("background-color:transparent");
//    ui->spellList->setStyleSheet("background-color:transparent");
//    ui->favButton->setStyleSheet("background-color:transparent");
//    ui->searchBar->setStyleSheet("background-color:rgb(231,208,166);");


    // Set the table widget to highlight its entire row
    ui->spellList->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Set the table headers
    QStringList headers = {"Name", "School", "Level"};
    //ui->spellList->setHorizontalHeaderLabels(headers);
//    for (int i = 0; i < headers.size(); i++) {
//        ui->spellList->setHorizontalHeaderItem(i, new QTableWidgetItem(headers[i]));
//    }
    //ui->spellList->horizontalHeader()->setVisible(true);


    // Read and parse the spell list
    //std::string filename = "5e-SRD-Spells.json";
    QFile qspellfile(":/resources/spells/Spells.json");
    qspellfile.open(QIODevice::ReadOnly);
    spells = read_spell_file(&qspellfile);
    qspellfile.close();

    //std::cout << "Read spell file" << std::endl;

    // Add the spells to the QTableWidget and display them
    populate_spell_table();

    //std::cout << "Populated spell table" << std::endl;

    // Add the "None" option for the second sort ComboBox
    ui->sort2Box->addItem(QString::fromStdString("None"));

    // Add the options to the sort ComboBoxes
    //std::cout << "n_sortable is " << SpellSortField::n_fields() << std::endl;
    for (auto x : SpellSortField::instances()) {
        std::string_view name = x.name();
        ui->sort1Box->addItem(QLatin1String(name.data(), name.size()));
        ui->sort2Box->addItem(QLatin1String(name.data(), name.size()));
    }

    //std::cout << "Added combo box options" << std::endl;

    // Set the Name option on the second sort box to be red, as this is the starting selection for the first sort box
    ui->sort2Box->setItemData(1, QBrush(Qt::red), Qt::TextColorRole);

    // Add the class and subclass names to the filter ComboBox
    ui->filterBox->addItem(QString::fromStdString("None"));
    for (const auto& elt : CasterClass::instances()) {
        std::string_view name = elt.name();
        ui->filterBox->addItem(QLatin1String(name.data(), name.size()));
    }

    //std::cout << "Finished combo boxes" << std::endl;

    /*
    for (const std::string& sname : subclassNames) {
        ui->filterBox->addItem(QString::fromStdString(sname));
    }
    */

    // Add the sourcebooks to the selector
//    QStandardItemModel sourcebookModel(N_SOURCES, 1);
//    for (size_t i = 0; i < N_SOURCES; i++) {
//        QStandardItem* item = new QStandardItem(QString::fromStdString(sourcebookNames[i]));
//        item->setFlags((Qt::ItemIsUserCheckable | Qt::ItemIsEnabled));
//        if (i == 0) {
//            item->setData(Qt::Checked, Qt::CheckStateRole);
//        } else {
//            item->setData(Qt::Unchecked, Qt::CheckStateRole);
//        }
//        std::cout << sourcebookNames[i] << std::endl;
//        sourcebookModel.setItem(i, item);
//    }
//    std::cout << sourcebookModel.rowCount() << std::endl;
//    ui->sourcebookSelector->setModel(&sourcebookModel);

    // Font settings
    QString fontstyle = QString::fromStdString("font-weight: 750");
    ui->sort1Label->setStyleSheet(fontstyle);
    ui->sort2Label->setStyleSheet(fontstyle);
    ui->filterLabel->setStyleSheet(fontstyle);

    // Make the table view not editable
    ui->spellList->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // The level/school/ritual label
    QFont levelSchoolFont = QFont("Scala Sans", 18, 1, true);
    ui->levelSchoolLabel->setFont(levelSchoolFont);
    ui->levelSchoolLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);

    // Make the labels selectable and set their font
    std::vector<QLabel*> labels = {
        ui->nameLabel, ui->concentrationLabel, ui->rangeLabel,
        ui->descriptionTitle, ui->descriptionLabel, ui->durationLabel, ui->componentsLabel, ui->castingTimeLabel,
        ui->pageLabel, ui->materialLabel, ui->classesLabel, ui->higherLevelTitle, ui->higherLevelLabel
    };
    QFont labelFont = QFont("Scala Sans", 11, 1);
    for (QLabel* p : labels) {
        p->setTextInteractionFlags(Qt::TextSelectableByMouse);
        p->setFont(labelFont);
    }

    // Set the spell title font
    QFont titleFont = QFont("Cloister Black", 40, 1);
    ui->nameLabel->setFont(titleFont);

    // Create the button pixmaps
    star_empty = QPixmap(":/resources/spells/star_empty.png");
    star_filled = QPixmap(":/resources/spells/star_filled_2.png");
    fav_icon = QIcon(star_filled);
    not_fav_icon = QIcon(star_empty);

    // The checkboxes for the sourcebooks
    sourcebookCheckboxes = {
        {Sourcebooks::PlayersHandbook, ui->phbCheckbox},
        {Sourcebooks::XanatharsGTE, ui->xgeCheckbox},
        {Sourcebooks::SwordCoastAG, ui->scagCheckbox}
    };

    // Create the arrow icons
    up_arrow = QPixmap(":/resources/icons/up_arrow.png");
    down_arrow = QPixmap(":/resources/icons/down_arrow.png");
    up_icon = QIcon(up_arrow);
    down_icon = QIcon(down_arrow);

    // Set the arrow icons
    ui->sortReverse1->setIcon(down_icon);
    ui->sortReverse2->setIcon(down_icon);
    ui->sortReverse1->setIconSize(QSize(arrowSize,arrowSize));
    ui->sortReverse2->setIconSize(QSize(arrowSize,arrowSize));

    // Load favorites
    load_favorites();

    //std::cout << "Finished spellbook setup" << std::endl;
}

Spellbook::~Spellbook()
{
    delete ui;
}


////// Slot functions //////

void Spellbook::on_spellList_clicked(const QModelIndex &index)
{
    display_spelldata(spells[index.row()]);
}


void Spellbook::on_sort1Box_currentIndexChanged(const QString&)
{
    sort();
}


void Spellbook::on_sort2Box_currentIndexChanged(const QString&)
{
    sort();
}



void Spellbook::on_filterBox_currentIndexChanged(int) // Unnamed: index
{
    filter();
}

void Spellbook::on_spellList_currentCellChanged(int currentRow, int, int, int) // Unnamed: currentColumn, previousRow, previousColumn
{
    display_spelldata(spells[currentRow]);
}

void Spellbook::on_favoritesButton_clicked()
{
    filter();
}

void Spellbook::on_favoritesButton_released()
{
    //filter();
}

void Spellbook::on_favButton_clicked()
{
    int index = ui->spellList->currentRow();
    if (index < 0) { return; }

    profile.toggle_favorite(spells[index]);
    update_button();
    save_favorites();

    if (ui->favoritesButton->isChecked()) {
        filter();
    }
}

void Spellbook::on_searchBar_textEdited(const QString&) // Unnamed: The QString in searchBar
{
    filter();
}

void Spellbook::on_phbCheckbox_toggled(bool) // Unnamed: checked
{
    sort();
    filter();
}

void Spellbook::on_xgeCheckbox_toggled(bool) // Unnamed: checked
{
    sort();
    filter();
}

void Spellbook::on_scagCheckbox_toggled(bool) // Unnamed: checked
{
    sort();
    filter();
}


////// Other methods //////
/// \brief Spellbook::populate_spell_table
///

// What to do when the window resizes
// The layouts will handle the sizes of the windows themselves
// But we need to adjust the column widths within the QTableWidget
void Spellbook::resizeEvent(QResizeEvent*) { // event parameter unused
    int width = ui->spellList->size().width();
    ui->spellList->setColumnWidth(0, static_cast<int>(std::floor(width * .5)));
    ui->spellList->setColumnWidth(1, static_cast<int>(std::floor(width * .35)));
    ui->spellList->setColumnWidth(2, static_cast<int>(std::floor(width * .15)));
}

void Spellbook::populate_spell_table() {
    ui->spellList->setRowCount(spells.size());
    ui->spellList->setColumnCount(3);
    for (int i = 0; i < spells.size(); ++i) {
        ui->spellList->setItem(i,0,new QTableWidgetItem(QString::fromStdString(spells[i].name())));
        ui->spellList->setItem(i,1,new QTableWidgetItem(QLatin1String(spells[i].school().name().data())));
        ui->spellList->setItem(i,2,new QTableWidgetItem(QString::number(spells[i].level())));
    }
}

void Spellbook::unfilter() {
    for (int i = 0; i < spells.size(); ++i) {
        ui->spellList->setRowHidden(i, false);
    }
}

void Spellbook::save_favorites() {
    std::ofstream ofs{favorites_file};
    for (int i = 0; i < spells.size(); i++) {
        if (profile.is_favorite(spells[i])) {
            ofs << spells[i].name() << std::endl;
        }
    }
}

void Spellbook::load_favorites() {
    std::string line;
    std::ifstream ifs{favorites_file};
    while (std::getline(ifs, line)) {
        bool inSpellbook = false;
        for (int i = 0; i < spells.size(); ++i) {
            Spell s = spells[i];
            if (line == s.name()) {
                profile.set_favorite(s);
                inSpellbook = true;
                break;
            }
        }
    }
}

bool Spellbook::filter_item(const bool isClass, const bool isFav, const bool isText, const Spell& s, const CasterClass& cc, const std::string& text) {
   if (sourcebookCheckboxes.size() == 0) {
       sourcebookCheckboxes = {
           {Sourcebooks::PlayersHandbook, ui->phbCheckbox},
           {Sourcebooks::XanatharsGTE, ui->xgeCheckbox},
           {Sourcebooks::SwordCoastAG, ui->scagCheckbox}
       };
   }
    bool toHide = false;
    std::string spname = s.name();
    to_lowercase(spname);
    toHide = toHide || (isClass && !s.usable_by(cc));
    toHide = toHide || (isFav && !profile.is_favorite(s));
    toHide = toHide || (isText && !boost::contains(spname, text));
    toHide = toHide || ( !sourcebookCheckboxes.at(s.sourcebook())->isChecked() );
    return toHide;
}

void Spellbook::filter() {
    std::string class_text = ui->filterBox->currentText().toStdString();
    bool isClass = !( (class_text == none_field) || class_text.empty() );
    const DnD::CasterClass& cc = isClass ? DnD::CasterClass::from_name(class_text) : DnD::CasterClasses::Wizard;
    bool favorites = ui->favoritesButton->isChecked();
    std::string search_text = ui->searchBar->text().toStdString();
    to_lowercase(search_text);
    bool isText = !search_text.empty();
//    if (!(isText || favorites || isClass) ) {
//        unfilter();
//    } else {
        for (int i = 0; i < spells.size(); ++i) {
            //std::cout << spells[i].name() << std::endl;
            ui->spellList->setRowHidden(i, filter_item(isClass, favorites, isText, spells[i], cc, search_text));
        }
    //}

}

void Spellbook::sort() {

    using DnD::Spell;

    // If this entry is greyed out, do nothing
    int index1 = ui->sort1Box->currentIndex();
    int index2 = ui->sort2Box->currentIndex();
    if (index2 == index1 + 1) { return; }

    // Get the strings
    QString qstr1 = ui->sort1Box->currentText();
    QString qstr2 = ui->sort2Box->currentText();

    // If the entry is set to None, do nothing
    if (qstr1.toStdString() == "None") {return;}

    // Get the sort fields
    std::string sort_field1_str = qstr1.toStdString();
    std::string sort_field2_str = qstr2.toStdString();
    SpellSortField sort_field1 = SpellSortField::from_name(sort_field1_str);
    bool sf2_is_none = (sort_field2_str == none_field);
    SpellSortField sort_field2 = !sf2_is_none ? SpellSortField::from_name(sort_field2_str) : SpellSortField::Name;

    // We have a map of the form string -> -1,0,1 comparison function
    // So we choose the correct comparison functions for the sort fields, then create the comparator from the comparison functions
    // Use this comparator to sort the list
    // We can fall back to the one-level sorted if the second field is None, the first field is Name, or the two sort fields are equal

    auto default_TC = SpellSortField::default_tricomparator();
    auto TC1 = sort_field1.tricomparator(reverse1);
    auto TC2 = sort_field2.tricomparator(reverse2);
    bool need_two_levels = !( sf2_is_none || (sort_field1 == SpellSortField::Name) || (sort_field1 == sort_field2) );
    Comparator<Spell> lt_comp = need_two_levels ? comparator(TC1, TC2, default_TC) : comparator(TC1, default_TC);
    std::sort(spells.begin(), spells.end(), lt_comp);

    // Clear the QListWidget and repopulate with the sorted list
    for (int i = 0; i < spells.size(); i++) {
        //std::cout << i << std::endl;
        ui->spellList->setItem(i,0,new QTableWidgetItem(QString::fromStdString(spells[i].name())));
        ui->spellList->setItem(i,1,new QTableWidgetItem(QLatin1String(spells[i].school().name().data())));
        ui->spellList->setItem(i,2,new QTableWidgetItem(QString::number(spells[i].level())));
    }

    // Redo hiding, if necessary
    int index = ui->filterBox->currentIndex();
    on_filterBox_currentIndexChanged(index);
}

void Spellbook::show_current_spell() {
    int current_index = ui->spellList->currentRow();
    display_spelldata(spells[current_index]);
}


void Spellbook::display_spelldata(const Spell& spell) {

    // Create the display text
    QString nameText = QString::fromStdString(spell.name());
    QString levelSchoolText = QString::fromStdString(spell.school_level_string());
    QString concentrationText = prompt_text("Concentration", yn_qstring(spell.concentration()));
    QString rangeText = prompt_text("Range", spell.range().string());
    QString descTitleText = QStringLiteral("<b>Description:</b>");
    QString descriptionText = QString::fromStdString(spell.description());
    QString higherLevelText = QString::fromStdString(spell.higher_level());
    QString durationText = prompt_text("Duration", spell.duration().string());
    QString castingTimeText = prompt_text("Casting time", spell.casting_time());
    std::string locationText = std::string(spell.sourcebook().abbreviation()) + " " + std::to_string(spell.page());
    QString pageText = prompt_text("Location", locationText);
    QString compText = prompt_text("Components", spell.components_string());
    QString materialText = QString::fromStdString(spell.material());

    std::string classes_string;
    QString classesText;
    for (const CasterClass& cclass : spell.classes()) {
        classes_string += cclass.name();
        classes_string += ", ";
    }
    if (spell.classes().size() > 0) {
        classes_string.erase(classes_string.end()-2,classes_string.end());
        classesText = prompt_text("Classes", classes_string);
    } else {
        classesText = QStringLiteral("");
    }

    /*
    std::string subclassesString;
    QString subclassesText;
    for (const Subclass& sclass : spell.subclasses) {
        subclassesString += subclassNames[static_cast<int>(sclass)];
        subclassesString += ", ";
    }
    if (spell.subclasses.size() > 0) {
        subclassesString.erase(subclassesString.end()-2,subclassesString.end());
        subclassesText = "<b>Subclasses: </b>" + QString::fromStdString(subclassesString);
    } else {
        subclassesText = "";
    }
    */

    // Add the appropriate text to the labels
    ui->nameLabel->setText(nameText);
    ui->levelSchoolLabel->setText(levelSchoolText);
    ui->concentrationLabel->setText(concentrationText);
    ui->rangeLabel->setText(rangeText);
    ui->durationLabel->setText(durationText);
    ui->componentsLabel->setText(compText);
    ui->castingTimeLabel->setText(castingTimeText);
    ui->pageLabel->setText(pageText);
    ui->classesLabel->setText(classesText);
    ui->descriptionTitle->setText(descTitleText);
    ui->descriptionLabel->setText(descriptionText);
    set_text_hide_empty(ui->materialLabel, "Materials", materialText);
    if (!spell.higher_level().empty()) {
        ui->higherLevelTitle->setText("<b>Higher level:</b>");
        ui->higherLevelLabel->setText(higherLevelText);
        ui->higherLevelTitle->show();
        ui->higherLevelLabel->show();
    } else {
        ui->higherLevelTitle->clear();
        ui->higherLevelLabel->clear();
        ui->higherLevelTitle->hide();
        ui->higherLevelLabel->hide();
    }
    //ui->subclassesLabel->setText(subclassesText);

    // Show the favorite button image
    update_button();
}

void Spellbook::update_button() {
    int index = ui->spellList->currentRow();
    Spell s = spells[index];
    if (profile.is_favorite(s)) {
        ui->favButton->setIcon(fav_icon);
    } else {
        ui->favButton->setIcon(not_fav_icon);
    }
    ui->favButton->setIconSize(QSize(iconSize,iconSize));
}

void Spellbook::on_sort_button_clicked(bool& reverse, QPushButton* button) {

    reverse = !reverse;
    if (reverse) {
        button->setIcon(up_icon);
    } else {
        button->setIcon(down_icon);
    }
    button->setIconSize(QSize(arrowSize, arrowSize));
    sort();
}

void Spellbook::on_sortReverse1_clicked()
{
    on_sort_button_clicked(reverse1, ui->sortReverse1);
}

void Spellbook::on_sortReverse2_clicked()
{
    on_sort_button_clicked(reverse2, ui->sortReverse2);
}
