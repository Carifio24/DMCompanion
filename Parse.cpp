#include <vector>
#include <string>
#include <fstream>
#include <array>
#include <exception>
#include <iostream>
#include "jstring.h"
#include "Enumerations.h"
#include "Parse.h"
//#include <boost/algorithm/string/replace.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string.hpp>
#include <QTextStream>

const std::vector<std::string> schoolNames = {"Abjuration", "Conjuration", "Divination", "Enchantment", "Evocation", "Illusion", "Necromancy", "Transmutation"};

const std::vector<std::string> casterNames = {"Bard", "Cleric", "Druid", "Paladin", "Ranger", "Sorcerer", "Warlock", "Wizard"};

const std::vector<std::string> subclassNames = {"Land", "Lore", "Life", "Devotion", "Fiend"};

const std::vector<std::string> sourcebookNames = {"Player's Handbook", "Xanathar's Guide to Everything", "Sword Coast Adventurer's Guide"};

const std::vector<std::string> sourcebookCodes = {"PHB", "XGE", "SCAG"};

const size_t N_SCHOOLS = schoolNames.size();

const size_t N_CASTERS = casterNames.size();

const size_t N_SUBCLASSES = subclassNames.size();

const size_t N_SOURCES = sourcebookNames.size();

bool yn_to_bool(const std::string& yn) {
	if (yn == "no") {
		return false;
	}
	else if (yn == "yes") {
		return true;
	}
	else {
		throw std::runtime_error("Invalid yes/no entry");
	}
}

std::string bool_to_yn(const bool& yn) {
	if (yn) {
		return "yes";
	} else {
		return "no";
	}
}

std::array<bool,3> components(const Json::Value& comps) {
	std::array<bool,3> spellComps = {false, false, false};
	for (auto v : comps) {
        std::string vup = v.asString();
        boost::to_upper(vup);
        if (vup == "V") {
			spellComps[0] = true;
		}
        if (vup == "S") {
			spellComps[1] = true;
		}
        if (vup == "M") {
			spellComps[2] = true;
		}
	}
	return spellComps;
}

Spell parse_spell(const Json::Value& root) {

	// Create the spell and get the basic info
	Spell spell;
	spell.index = root["index"].asInt();
	spell.name = root["name"].asString();
    std::vector<std::string> pdata = jstring::split(root["page"].asString(), " ");
    spell.page = std::stoi(pdata[pdata.size()-1]);
    std::string bookCode = pdata[0];
    boost::to_upper(bookCode);
    spell.sourcebook = enum_from_name<Sourcebook>(sourcebookCodes, bookCode);
    spell.range = root["range"].asString();
    spell.castingTime = root["casting_time"].asString();
    spell.level = root["level"].asInt();
    spell.duration = root["duration"].asString();
    if (boost::starts_with(spell.duration, "Up to")) {
        spell.concentration = true;
    } else if (root.isMember("concentration")) {
        spell.concentration = yn_to_bool(root["concentration"].asString());
    } else {
        spell.concentration = false;
    }
    if (root.isMember("ritual")) {
        spell.ritual = yn_to_bool(root["ritual"].asString());
    } else {
        spell.ritual = false;
    }

	// Get the spell's description
	std::string desc;
    bool first = true;
	for (const auto& x : root["desc"]) {
        if (!first) {
            desc += "    ";
        }
        desc += x.asString();
        desc += "\n";
        first = false;
	}
    desc.erase(desc.end()-1,desc.end());
    //boost::replace_all(desc, "â€™", "\'");
    //boost::replace_all(desc, "â€¢", "-");
    //boost::replace_all(desc, "â€”", "—");
    //boost::replace_all(desc, "â€“", "—");
    //boost::replace_all(desc, "â€œ", "\"");
    //boost::replace_all(desc, "â€�", "\"");
	spell.description = desc;

	// Get the spell components
	spell.components = components(root["components"]);

	// Get the material component description, if required
	if (spell.components[2]) {
		std::string mat = root["material"].asString();
        //boost::replace_all(mat, "â€™", "\'");
		spell.material = mat;
	} else {
		spell.material = "";
	}

	// Get the school
	spell.school = enum_from_name<School>(schoolNames, root["school"]["name"].asString());

	// Get the caster classes
	std::vector<CasterClass> classes;
	for (const auto& v : root["classes"]) {
        try {
            classes.push_back(enum_from_name<CasterClass>(casterNames, v["name"].asString()));
        }
        catch (Json::LogicError) {
            classes.push_back(enum_from_name<CasterClass>(casterNames, v.asString()));
        }
	}
	classes.shrink_to_fit();
	spell.classes = classes;

	// Get the subclasses
	std::vector<Subclass> subclasses;
	for (const auto& v : root["subclasses"]) {
		subclasses.push_back(enum_from_name<Subclass>(subclassNames, v["name"].asString()));
	}
	subclasses.shrink_to_fit();
	spell.subclasses = subclasses;

    spell.favorite = false;

	return spell;

}

std::vector<Spell> read_spellfile(QFile* qspellfile) {

    std::cout << qspellfile->fileName().toStdString() << std::endl;
    QTextStream in(qspellfile);
    std::string data = in.readAll().toStdString();

	Json::Value root;
	Json::CharReaderBuilder builder;
	Json::CharReader* reader = builder.newCharReader();
	std::string errors;
    //std::string data((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
	reader->parse(data.c_str(), data.c_str() + data.size(), &root, &errors);

	std::vector<Spell> spells;
	for (Json::Value& w : root) {
		spells.push_back(parse_spell(w));
	}
	spells.shrink_to_fit();
	return spells;
}
