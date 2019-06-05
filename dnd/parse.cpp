#include <vector>
#include <string>
#include <fstream>
#include <array>
#include <exception>
#include <iostream>
#include <locale>
#include <utility>
#include <regex>

#include <assert.h>

#include "string_helpers.h"
#include "json_helpers.h"
#include "enumerations.h"
#include "parse.h"
#include "monster.h"
#include "enummaps.h"
#include "damage_info.h"

#include <boost/algorithm/string/replace.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string.hpp>

#include <QTextStream>

// General-purpose methods

std::pair<int,Die> dice_from_string(const std::string& s) {
    std::vector<std::string> dice_vals = jstring::split(s, "d");
    int n_dice = std::stoi(dice_vals[0]);
    Die dtype = static_cast<Die>(std::stoi(dice_vals[1]));
    auto dice = std::make_pair(n_dice, dtype);
    return dice;
}


std::vector<Spell> read_spellfile(QFile* qspellfile) {

    std::cout << qspellfile->fileName().toStdString() << std::endl;
    QTextStream in(qspellfile);
    std::string data = in.readAll().toStdString();

	Json::Value root;
	Json::CharReaderBuilder builder;
	Json::CharReader* reader = builder.newCharReader();
	std::string errors;
	reader->parse(data.c_str(), data.c_str() + data.size(), &root, &errors);

	std::vector<Spell> spells;
	for (Json::Value& w : root) {
		spells.push_back(parse_spell(w));
	}
	spells.shrink_to_fit();
	return spells;
}


std::vector<Monster> read_monsterfile(QFile* qmonsterfile) {

    std::cout << qmonsterfile->fileName().toStdString() << std::endl;
    QTextStream in(qmonsterfile);
    std::string data = in.readAll().toStdString();

    Json::Value root;
    Json::CharReaderBuilder builder;
    Json::CharReader* reader = builder.newCharReader();
    std::string errors;
    reader->parse(data.c_str(), data.c_str() + data.size(), &root, &errors);

    std::vector<Monster> monsters;
    for (Json::Value& w : root) {

        // Skip the license
        if (w.isMember("license")) { continue; }

        monsters.push_back(parse_monster(w));
    }
    monsters.shrink_to_fit();

    for (const Monster& m : monsters) {
        std::cout << m.name << std::endl;
    }

    return monsters;
}
