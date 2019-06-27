#include "spellbook.h"
#include "ui_spellbook.h"
#include "spell_parse.h"
#include "sort.h"
#include "qdisplay.h"
#include "jsoncpp/json/json.h"
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <QFile>
#include <QCheckBox>
#include <QStringView>
#include <QStringBuilder>
#include <QStandardItemModel>

#include <cmath>
#include <fstream>
#include <iostream>

#include <DnD/caster_class.h>
#include <DnD/spell.h>
#include <DnD/converters.h>
#include <DnD/duration.h>
#include <DnD/converters.h>

using namespace DnD;

Spellbook::Spellbook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Spellbook)
{
    using namespace DnD;

    ui->setupUi(this);

    // Set the title
    setWindowTitle(QString::fromStdString("D&D 5th edition spellbook"));

    // Set items to be transparent
//    setStyleSheet("background-color:transparent");
//    ui->descScrollArea->setStyleSheet("background-color:transparent");
//    ui->spellList->setStyleSheet("background-color:transparent");
//    ui->favButton->setStyleSheet("background-color:transparent");
    //ui->searchBar->setStyleSheet("background-color:rgb(231,208,166);");


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
    QFile qspellfile(":/resources/Spells.json");
    qspellfile.open(QIODevice::ReadOnly);
    spells = read_spell_file(&qspellfile);
    qspellfile.close();

    std::cout << "Read spell file" << std::endl;

    // Add the spells to the QTableWidget and display them
    populate_spell_table();

    std::cout << "Populated spell table" << std::endl;

    // Add the "None" option for the second sort ComboBox
    ui->sort2Box->addItem(QString::fromStdString("None"));

    // Add the options to the sort ComboBoxes
    std::cout << "n_sortable is " << n_sortable << std::endl;
    for (size_t i = 0; i < n_sortable; i++) {
        std::cout << i << std::endl;
        std::cout << spell_sort_fields[i] << std::endl;
        ui->sort1Box->addItem(QString::fromStdString(spell_sort_fields[i]));
        std::cout << "Here" << std::endl;
        ui->sort2Box->addItem(QString::fromStdString(spell_sort_fields[i]));
    }

    std::cout << "Added combo box options" << std::endl;

    // Set the Name option on the second sort box to be red, as this is the starting selection for the first sort box
    ui->sort2Box->setItemData(1, QBrush(Qt::red), Qt::TextColorRole);

    // Add the class and subclass names to the filter ComboBox
    ui->filterBox->addItem(QString::fromStdString("None"));
    for (const auto& elt : CasterClasses::instances) {
        std::string_view name = elt->name();
        ui->filterBox->addItem(QLatin1String(name.data(), name.size()));
    }

    std::cout << "Finished combo boxes" << std::endl;

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

    // Make the labels selectable
    std::vector<QLabel*> labels = {
        ui->nameLabel, ui->schoolLabel, ui->ritualLabel,ui->concentrationLabel, ui->levelLabel, ui->rangeLabel,
        ui->descriptionTitle, ui->descriptionLabel, ui->durationLabel, ui->componentsLabel, ui->castingTimeLabel,
        ui->pageLabel, ui->materialLabel, ui->classesLabel
    };
    for (QLabel* p : labels) {
        p->setTextInteractionFlags(Qt::TextSelectableByMouse);
    }

    // Create the button pixmaps
    star_empty = QPixmap(":/resources/star_empty.png");
    star_filled = QPixmap(":/resources/star_filled_2.png");
    fav_icon = QIcon(star_filled);
    not_fav_icon = QIcon(star_empty);

    // The checkboxes for the sourcebooks
    sourcebookCheckboxes = {
        {Sourcebooks::PlayersHandbook, ui->phbCheckbox},
        {Sourcebooks::XanatharsGTE, ui->xgeCheckbox},
        {Sourcebooks::SwordCoastAG, ui->scagCheckbox}
    };

    // Load favorites
    load_favorites();

    std::cout << "Finished spellbook setup" << std::endl;
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
    filter();
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
void Spellbook::resizeEvent(QResizeEvent* event) {
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

        if (!inSpellbook) {
            throw std::runtime_error("Bad spell name!");
        }
    }
}

bool Spellbook::filter_item(const bool& isClass, const bool& isFav, const bool& isText, const Spell& s, const CasterClass& cc, const std::string& text) {
   if (sourcebookCheckboxes.size() == 0) {
       sourcebookCheckboxes = {
           {Sourcebooks::PlayersHandbook, ui->phbCheckbox},
           {Sourcebooks::XanatharsGTE, ui->xgeCheckbox},
           {Sourcebooks::SwordCoastAG, ui->scagCheckbox}
       };
   }
    bool toHide = false;
    std::string spname = s.name();
    boost::to_lower(spname);
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
    std::string searchText = ui->searchBar->text().toStdString();
    boost::to_lower(searchText);
    bool isText = (searchText != "");
//    if (!(isText || favorites || isClass) ) {
//        unfilter();
//    } else {
        for (int i = 0; i < spells.size(); ++i) {
            std::cout << spells[i].name() << std::endl;
            ui->spellList->setRowHidden(i, filter_item(isClass, favorites, isText, spells[i], cc, searchText));
        }
    //}

}

void Spellbook::sort() {

    using DnD::Spell;

    // If this entry is greyed out, do nothing
    int index1 = ui->sort1Box->currentIndex();
    int index2 = ui->sort2Box->currentIndex();
    if (index2 == index1 + 1) {return;}

    // Get the strings
    QString qstr1 = ui->sort1Box->currentText();
    QString qstr2 = ui->sort2Box->currentText();

    // If the entry is set to None, do nothing
    if (qstr1.toStdString() == "None") {return;}

    // Get the sort fields
    std::string sort_field1 = qstr1.toStdString();
    std::string sort_field2 = qstr2.toStdString();

    // We have a map of the form string -> -1,0,1 comparison function
    // So we choose the correct comparison functions for the sort fields, then create the comparator from the comparison functions
    // Use this comparator to sort the list
    std::function<bool(const Spell&, const Spell&)> lt_comp;
    if ( (sort_field2 == none_field) || (sort_field1 == default_spell_field) || (sort_field1 == sort_field2) ) {
        lt_comp = [&sort_field1](const Spell& s1, const Spell& s2) { return less_than(s1, s2, spell_sort_fns.at(sort_field1), spell_sort_fns.at(default_spell_field)); };
    } else {
         lt_comp = [&sort_field1, &sort_field2](const Spell& s1, const Spell& s2) { return less_than(s1, s2, spell_sort_fns.at(sort_field1), spell_sort_fns.at(sort_field2), spell_sort_fns.at(default_spell_field)); };
    }
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
    QString schoolText = prompt_text("School", QString(spell.school().name().data()));
    QString ritualText = prompt_text("Ritual", yn_qstring(spell.ritual()));
    QString concentrationText = prompt_text("Concentration", yn_qstring(spell.concentration()));
    QString levelText = prompt_text("Level", QString::number(spell.level()));
    QString rangeText = prompt_text("Distance", spell.range().string());
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
    ui->schoolLabel->setText(schoolText);
    ui->ritualLabel->setText(ritualText);
    ui->concentrationLabel->setText(concentrationText);
    ui->levelLabel->setText(levelText);
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
