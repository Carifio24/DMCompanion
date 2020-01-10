#ifndef MONSTERMANUAL_H
#define MONSTERMANUAL_H

#include <QFile>
#include <QIcon>
#include <QLabel>
#include <QWidget>
#include <QPushButton>

#include "dnd/monster.h"

namespace Ui {
class MonsterManual;
}

class MonsterManual : public QWidget
{
    Q_OBJECT

public:
    explicit MonsterManual(QWidget *parent = 0);
    ~MonsterManual();

private slots:
    void on_monsterTable_clicked(const QModelIndex &index);

    void on_monsterTable_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

    void on_searchBar_textEdited(const QString &arg1);

    void on_sortComboBox_currentIndexChanged(const QString &arg1);

    void on_sortReverse_clicked();

private:
    bool filter_item(const DnD::Monster& m, const bool filter_text, const std::string& text);
    void filter();
    void populate_monster_table();
    void display_monster_data(const DnD::Monster& m);
    void read_monster_file(QFile* qmonsterfile);
    void sort();
     void on_sort_button_clicked(bool& reverse, QPushButton* button);

    static constexpr int image_width = 300;
    static constexpr int image_height = 300;

    std::string placeholder_image_file = "resources/monsters/monster_images/Placeholder.jpeg";
    Ui::MonsterManual *ui;
    QVector<DnD::Monster> monsters;
    std::map<std::string,std::string> monster_filenames;
    int arrowSize = 25;
    QPixmap up_arrow;
    QPixmap down_arrow;
    QIcon up_icon;
    QIcon down_icon;
    bool reverse = false;
};

#endif // MONSTERMANUAL_H
