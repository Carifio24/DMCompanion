#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include "sort.h"
#include "profile.h"

#include <string>
#include <vector>
#include <QWidget>
#include <QCheckBox>
#include <QIcon>
#include <QPixmap>
#include <DnD/spell.h>
#include <DnD/sourcebook.h>
#include <DnD/ref_wrap_comp.h>

namespace Ui {
class Spellbook;
}

class Spellbook : public QWidget
{
    Q_OBJECT

public:
    explicit Spellbook(QWidget *parent = 0);
    ~Spellbook();
    QVector<DnD::Spell> spellsList() {return spells;}

private slots:
    void on_spellList_clicked(const QModelIndex &index);

    void on_sort1Box_currentIndexChanged(const QString &arg1);

    void on_sort2Box_currentIndexChanged(const QString &arg1);

    void on_filterBox_currentIndexChanged(int);

    void on_spellList_currentCellChanged(int currentRow, int, int, int);

    void on_favoritesButton_clicked();

    void on_favoritesButton_released();

    void on_favButton_clicked();

    void on_searchBar_textEdited(const QString &arg1);

    void on_phbCheckbox_toggled(bool checked);

    void on_xgeCheckbox_toggled(bool checked);

    void on_scagCheckbox_toggled(bool checked);

private:

    void resizeEvent(QResizeEvent* event);

    void filter_by_class(const DnD::CasterClass& cc);

    void filter_favorites();

    void filter_with_favorites(const DnD::CasterClass& cc);

    void filter();

    void save_favorites();

    void load_favorites();

    void unfilter();

    void update_button();

    bool filter_item(const bool& isClass, const bool& isFav, const bool& isText, const DnD::Spell& s, const DnD::CasterClass& cc, const std::string& text);

    void populate_spell_table();

    Ui::Spellbook *ui;
    QVector<DnD::Spell> spells;
    void sort();
    void display_spelldata(const DnD::Spell& spell);
    void show_current_spell();
    std::string favorites_file = "Favorites.txt";

    QPixmap star_empty;
    QPixmap star_filled;
    QIcon fav_icon;
    QIcon not_fav_icon;
    int iconSize = 40;
    Profile profile;

    std::map<std::reference_wrapper<const DnD::Sourcebook>,QCheckBox*,ref_wrap_comp> sourcebookCheckboxes;

};

#endif // SPELLBOOK_H
