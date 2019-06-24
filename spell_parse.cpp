#include <string>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <iostream>

#include <QFile>
#include <QVector>
#include <QTextStream>

#include <DnD/school.h>
#include <DnD/duration.h>
#include <DnD/sourcebook.h>
#include <DnD/caster_class.h>
#include <DnD/string_helpers.h>
#include <DnD/converters.h>
#include <DnD/dice_set.h>

#include "spell_parse.h"

// Spellbook-specific methods

using namespace DnD;

std::array<bool,3> components(const Json::Value& comps) {
	std::array<bool,3> spellComps = {false, false, false};
	for (auto v : comps) {
        std::string vup = v.asString();
        std::transform(vup.begin(), vup.end(), vup.begin(), ::toupper);
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

DnD::Spell parse_spell(const Json::Value& root, DnD::SpellBuilder& b) {

    using namespace DnD;
    using namespace DnD::keys;

	// Create the spell and get the basic info
    b.set_name(root[name_k].asString());
    std::cout << root[name_k].asString() << std::endl;
    std::vector<std::string> pdata = split(root[page_k].asString(), " ", 2);
    b.set_page(std::stoi(pdata[1]));
    std::string bookCode = pdata[0];
    const Sourcebook& sourcebook = Sourcebook::from_abbreviation(bookCode);
    b.set_sourcebook(sourcebook);
    std::string range_str = root[range_k].asString();
    std::cout << range_str << std::endl;
    Distance range = Distance::from_string(range_str);
    b.set_range(range);
    b.set_casting_time(root[casting_time_k].asString());
    b.set_level(root[level_k].asInt());
    std::string durationStr = root[duration_k].asString();
    Duration duration = Duration::from_string(durationStr);
    b.set_duration(duration);
    if (starts_with(durationStr, "Up to")) {
        b.set_concentration(true);
    } else if (root.isMember(concentration_k)) {
        b.set_concentration(yn_to_bool(root[concentration_k].asString()));
    } else {
        b.set_concentration(false);
    }
    if (root.isMember(ritual_k)) {
        b.set_ritual(yn_to_bool(root[ritual_k].asString()));
    } else {
        b.set_ritual(false);
    }

    std::cout << "About to get description" << std::endl;

	// Get the spell's description
    bool first = true;
    std::stringstream ss;
	for (const auto& x : root[description_k]) {
        if (!first) {
            ss << "    "; // We use four spaces for paragraph indentation
        } else {
            first = false;
        }
        ss << x.asString() << "\n";
	}
    std::string desc = ss.str();
    ss.str(std::string()); // Clear the stringstream
    desc.erase(desc.end()-1,desc.end());
    //boost::replace_all(desc, "â€™", "\'");
    //boost::replace_all(desc, "â€¢", "-");
    //boost::replace_all(desc, "â€”", "—");
    //boost::replace_all(desc, "â€“", "—");
    //boost::replace_all(desc, "â€œ", "\"");
    //boost::replace_all(desc, "â€�", "\"");
	b.set_description(desc);

    std::cout << "Set description" << std::endl;

    // Get the higher level description
    first = true;
    std::string hl_desc;
    if (root.isMember(higher_level_k)) {
        for (const auto& x : root[higher_level_k]) {
            std::cout << "x is " << x << std::endl;
            if (!first) {
                ss << "    "; // We use four spaces for paragraph indentation
            } else {
                first = false;
            }
            ss << x.asString() << "\n";
        }
        hl_desc = ss.str();
        ss.str(std::string()); // Clear the stringstream
        hl_desc.erase(hl_desc.end()-1,hl_desc.end());
    }
    b.set_higher_level(hl_desc);

    std::cout << "Finished higher level" << std::endl;

	// Get the spell components
    auto comps = components(root[components_k]);
	b.set_components(comps);

	// Get the material component description, if required
	if (comps[2]) {
		std::string mat = root[material_k].asString();
        //boost::replace_all(mat, "â€™", "\'");
		b.set_material(mat);
	} else {
		b.set_material("");
	}

	// Get the school
    std::string school_str = root[school_k][name_k].asString();
	const School& school = School::from_name(school_str);
    b.set_school(school);

	// Get the caster classes
	std::vector<std::reference_wrapper<const CasterClass>> classes;
    Json::Value classesJSON = root[classes_k];
    classes.reserve(classesJSON.size());
	for (const auto& v : classesJSON) {
        std::string class_str;
        try {
            class_str = v[name_k].asString();
        }
        catch (Json::LogicError) {
            class_str = v.asString();
        }
        classes.push_back(std::cref(CasterClass::from_name(class_str)));
	}
	b.set_classes(classes);

	Spell spell = b.build_and_reset();
    return spell;

}

QVector<Spell> read_spell_file(QFile* qspellfile) {

    std::cout << qspellfile->fileName().toStdString() << std::endl;
    QTextStream in(qspellfile);
    std::string data = in.readAll().toStdString();

    Json::Value root;
    Json::CharReaderBuilder builder;
    Json::CharReader* reader = builder.newCharReader();
    std::string errors;
    reader->parse(data.c_str(), data.c_str() + data.size(), &root, &errors);

    QVector<Spell> spells;
    SpellBuilder b;
    spells.reserve(root.size());
    for (Json::Value& w : root) {
        spells.push_back(parse_spell(w, b));
    }
    return spells;
}
