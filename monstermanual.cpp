#include "monstermanual.h"
#include "ui_monstermanual.h"
#include "monster_parse.h"
#include "monster_display.h"
#include "qdisplay.h"
#include "sort.hpp"
#include "keys.h"
#include <vector>
#include <iostream>
#include <functional>

#include <boost/algorithm/string/predicate.hpp>

#include <QFile>
#include <QLabel>
#include <QScrollBar>
#include <QTextStream>
#include <QStringBuilder>
#include <QFontDatabase>

#include "monster_parse.h"
#include "monster_sort_field.h"
#include "dnd/string_helpers.h"
#include "json_helpers.h"
#include "qhelpers.h"

using namespace DnD;

MonsterManual::MonsterManual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonsterManual)
{
    ui->setupUi(this);

    //std::cout << "Making monster manual" << std::endl;

    //Set items to be transparent

    // Read and parse the monster list
    QFile qmonsterfile(":/resources/monsters/Monsters.json");
    qmonsterfile.open(QIODevice::ReadOnly);
    read_monster_file(&qmonsterfile);
    qmonsterfile.close();

    // Set the font
//    QFont default_font = QFont("DejaVu Sans", 9, 1);
//    setFont(default_font);
//    ui->monsterTable->setFont(default_font);
//    std::cout << "Set Monster Manual font" << std::endl;

    // Sort the monsters by the default field (name)
    //std::cout << "About to sort" << std::endl;
    auto default_cmp = comparator(MonsterSortField::default_tricomparator());
    //std::cout << "Got the default comparator" << std::endl;
    std::sort(monsters.begin(), monsters.end(), default_cmp);
    //std::cout << "Done sorting" << std::endl;

    // Add the options to the sort ComboBox
    for (auto x : MonsterSortField::instances()) {
        std::string_view name = x.name();
        ui->sortComboBox->addItem(QLatin1String(name.data(), name.size()));
    }

    // Populate the monster table
    //std::cout << "About to populate monster table" << std::endl;
    populate_monster_table();

    // Make the table view not editable
    ui->monsterTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Set the table widget to highlight its entire row
    ui->monsterTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Make the labels selectable and set their fonts
    std::vector<QLabel*> labels = {
        ui->nameLabel, ui->acLabel, ui->hpLabel, ui->strLabel, ui->dexLabel, ui->conLabel, ui->intLabel, ui->wisLabel, ui->chaLabel,
        ui->speedLabel, ui->sensesLabel, ui->damageImmunitiesLabel, ui->damageResistancesLabel, ui->damageVulnerabilitiesLabel, ui->conditionImmunitiesLabel,
        ui->challengeRatingLabel, ui->skillsLabel, ui->sizeTypeLabel, ui->abilitiesLabel, ui->languagesLabel, ui->savingThrowsLabel
    };
    QFont labelFont = QFont("Scala Sans", 11, 1);
    for (QLabel* p : labels) {
        p->setTextInteractionFlags(Qt::TextSelectableByMouse);
        p->setFont(labelFont);
    }

    // Set name label font
    QFont titleFont = QFont("Cloister Black", 40, 1);
    ui->nameLabel->setFont(titleFont);

    // Set the table font
    //ui->monsterTable->setFont(QFont("DejaVu Sans", 12, 1));

    // Create the arrow icons
    up_arrow = QPixmap(":/resources/icons/up_arrow.png");
    down_arrow = QPixmap(":/resources/icons/down_arrow.png");
    up_icon = QIcon(up_arrow);
    down_icon = QIcon(down_arrow);

    // Set the arrow icon
    ui->sortReverse->setIcon(down_icon);
    ui->sortReverse->setIconSize(QSize(arrowSize, arrowSize));

}

MonsterManual::~MonsterManual()
{
    delete ui;
}


///// Slot functions /////

void MonsterManual::on_monsterTable_clicked(const QModelIndex &index)
{
    display_monster_data(monsters[index.row()]);
}

void MonsterManual::on_monsterTable_currentCellChanged(int currentRow, int, int, int) // Unused: currentColumn, previousRow, previousColumn
{
    display_monster_data(monsters[currentRow]);
}

///// Other methods /////

void MonsterManual::populate_monster_table() {
    ui->monsterTable->setRowCount(monsters.size());
    ui->monsterTable->setColumnCount(1);
    for (int i = 0; i < monsters.size(); ++i) {
        ui->monsterTable->setItem(i,0,new QTableWidgetItem(QString::fromStdString(monsters[i].name())));
    }
}

void MonsterManual::display_monster_data(const Monster& m) {

    //static constexpr int line_width = 3;

    // Reset scrollbar
    ui->abilitiesScrollArea->verticalScrollBar()->setValue(0);

    // Name
    ui->nameLabel->setText(QLatin1String(m.name().data()));

    // Size and type
    ui->sizeTypeLabel->setText(size_type_string(m));

    // Image
    std::string image_file = monster_filenames[m.name()];
    QString image_resource = ":/" % QString::fromStdString(image_file);
    QPixmap img(image_resource);
    img = img.scaled(image_width, image_height, Qt::KeepAspectRatioByExpanding);
    //img = img.scaled(image_width, image_height);
    ui->imageLabel->setScaledContents(true);
    ui->imageLabel->setPixmap(img);
    //ui->imageLabel->setFrameStyle(QFrame::Box);
    //ui->imageLabel->setLineWidth(line_width);

    // Basic stats
    QString ac_str = prompt_text("Armor class", m.armor_class());
    QString hp_str = prompt_text("Hit Points", hp_string(m));
    QString speed_str = prompt_text("Speed", speed_string(m));
    ui->acLabel->setText(ac_str);
    ui->hpLabel->setText(hp_str);
    ui->speedLabel->setText(speed_str);

    // Extra stats
    set_text_none_empty(ui->savingThrowsLabel, "Saving Throws", saving_throws_string(m));
    set_text_none_empty(ui->sensesLabel, "Senses", senses_string(m));
    set_text_none_empty(ui->skillsLabel, "Skills", skills_string(m));
    set_text_none_empty(ui->languagesLabel, "Languages", QString::fromStdString(m.languages()));
    set_text_none_empty(ui->damageImmunitiesLabel, "Damage Immunities", damage_immunities_string(m));
    set_text_none_empty(ui->damageVulnerabilitiesLabel, "Damage Vulnerabilities", damage_vulnerabilities_string(m));
    set_text_none_empty(ui->damageResistancesLabel, "Damage Resistances", damage_resistances_string(m));
    set_text_none_empty(ui->conditionImmunitiesLabel, "Condition Immunities", condition_immunities_string(m));
    set_text_none_empty(ui->challengeRatingLabel, "Challenge Rating", QString::fromStdString(m.challenge_rating().as_string()));

    // For multi-line QStrings
    static const QString separator = QStringLiteral("<br><font size=1><br></font>");
    static const QString newline = QStringLiteral("<br>");
    static const QString double_newline = QStringLiteral("<br><br>");

    // Ability scores
    ui->strLabel->setText(ability_score_text("STR", m.strength()));
    ui->dexLabel->setText(ability_score_text("DEX", m.dexterity()));
    ui->conLabel->setText(ability_score_text("CON", m.constitution()));
    ui->intLabel->setText(ability_score_text("INT", m.intelligence()));
    ui->wisLabel->setText(ability_score_text("WIS", m.wisdom()));
    ui->chaLabel->setText(ability_score_text("CHA", m.charisma()));

    // Special abilities, actions, and legendary actions
    QStringList qsl;

    // Special abilities
    std::vector<Feature> spcl_abls = m.special_abilities();
    if (spcl_abls.size() > 0) {
        //qsl << title_qstring("Special Abilities");
        for (const Feature& abl : spcl_abls) {
            qsl << as_qstring(abl);
        }
    }

    // Actions
    std::vector<Feature> actions = m.actions();
    if (actions.size() > 0) {
        qsl << title_qstring("Actions:");
        for (const Feature& act : actions) {
            qsl << as_qstring(act);
        }
    }

    // Legendary actions
    std::vector<Feature> leg_acts = m.legendary_actions();
    if (leg_acts.size() > 0) {
        qsl << title_qstring("Legendary Actions:");
        for (const Feature& lact : leg_acts) {
            qsl << as_qstring(lact);
        }
    }

    ui->abilitiesLabel->setText(qsl.join(separator));

}


void MonsterManual::sort() {

    // Get the sort field from its name
    QString sort_field_qstr = ui->sortComboBox->currentText();
    std::string sort_field_str = sort_field_qstr.toStdString();
    MonsterSortField sort_field = MonsterSortField::from_name(sort_field_str);

    // Get the comparator function
    BinaryIntFunc<DnD::Monster> sort_field_TC = sort_field.tricomparator(reverse);
    BinaryIntFunc<DnD::Monster> default_TC = MonsterSortField::default_tricomparator();
    Comparator<DnD::Monster> cmp = comparator(sort_field_TC, default_TC);

    // Sort the monsters
    std::sort(monsters.begin(), monsters.end(), cmp);

    // Clear the QListWidget and repopulate with the sorted list
    for (int i = 0; i < monsters.size(); i++) {
        ui->monsterTable->setItem(i,0,new QTableWidgetItem(QString::fromStdString(monsters[i].name())));
    }

}


bool MonsterManual::filter_item(const Monster& m, const bool filter_text, const std::string& text) {
    bool hide = false;
    std::string name = m.name();
    to_lowercase(name);
    hide = hide || (filter_text && !boost::contains(name, text));
    return hide;
}


void MonsterManual::filter() {
    std::string search_text = ui->searchBar->text().toStdString();
    bool filter_text = !search_text.empty();
    for (int i = 0; i < monsters.size(); ++i) {
        ui->monsterTable->setRowHidden(i, filter_item(monsters[i], filter_text, search_text));
    }

}

void MonsterManual::on_searchBar_textEdited(const QString&)
{
    filter();
}

void MonsterManual::read_monster_file(QFile* qmonsterfile) {

    //std::cout << qmonsterfile->fileName().toStdString() << std::endl;
    QTextStream in(qmonsterfile);
    std::string data = in.readAll().toStdString();

    Json::Value root;
    Json::CharReaderBuilder builder;
    Json::CharReader* reader = builder.newCharReader();
    std::string errors;
    reader->parse(data.c_str(), data.c_str() + data.size(), &root, &errors);

    MonsterBuilder b;
    //std::cout << "There are " << root.size() << " monsters" << std::endl;
    //std::cout << root.toStyledString() << std::endl;
    for (const Json::Value& w : root) {

        // Skip the license
        if (w.isMember("license")) { continue; }
        //std::cout << w.toStyledString() << std::endl;
        Monster m = parse_monster(w, b);
        monsters.push_back(m);
        std::string name = m.name();
        monster_filenames[name] = string_if_member(w, keys::image_filename_k, placeholder_image_file);
        //std::cout << monster_filenames[name] << std::endl;
        //std::cout << "Created monster with name " <<m.name() << std::endl;
    }

}

void MonsterManual::on_sort_button_clicked(bool& reverse, QPushButton* button) {

    reverse = !reverse;
    if (reverse) {
        button->setIcon(up_icon);
    } else {
        button->setIcon(down_icon);
    }
    button->setIconSize(QSize(arrowSize, arrowSize));
    sort();
}


void MonsterManual::on_sortComboBox_currentIndexChanged(const QString&)
{
    sort();
}

void MonsterManual::on_sortReverse_clicked()
{
    on_sort_button_clicked(reverse, ui->sortReverse);
}
