#include <string>
#include <cctype>
#include <sstream>
#include <algorithm>

#include "School.h"
#include "Duration.h"
#include "Sourcebook.h"
#include "SpellParse.h"
#include "CasterClass.h"
#include "StringHelpers.h"

namespace DnD {

// Spellbook-specific methods

std::array<bool,3> components(const Json::Value& comps) {
	std::array<bool,3> spellComps = {false, false, false};
	for (auto v : comps) {
        std::string vup = v.asString();
        std::transform(vup.begin(), vup.end(), vup.begin(), std::toupper);
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

Spell parse_spell(const Json::Value& root, SpellBuilder& b) {

    using namespace keys;

	// Create the spell and get the basic info
    b.set_name(root[name_k].asString());
    std::vector<std::string> pdata = split(root[page_k].asString(), " ", 2);
    b.set_page(std::stoi(pdata[1]));
    std::string bookCode = pdata[0];
    const Sourcebook& sourcebook = Sourcebook::from_abbreviation(bookCode);
    b.set_sourcebook(sourcebook);
    Distance range = Distance::from_string(root[range_k].asString());
    b.set_range(range);
    b.set_casting_time(root[casting_time_k].asString());
    b.set_level(root[level_k].asInt());
    std::string durationStr = root[duration_k].asString();
    Duration duration = Duration::fromString(durationStr);
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

    // Get the higher level description
    first = true;
	for (const auto& x : root[higher_level_k]) {
        if (!first) {
            ss << "    "; // We use four spaces for paragraph indentation
        } else {
            first = false;
        }
        ss << x.asString() << "\n";
	}
    std::string hl_desc = ss.str();
    ss.str(std::string()); // Clear the stringstream
    hl_desc.erase(hl_desc.end()-1,hl_desc.end());
    b.set_higher_level(hl_desc);

	// Get the spell components
	b.set_components(components(root[components_k]));

	// Get the material component description, if required
	if (spell.components[2]) {
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
	std::vector<CasterClass* const> classes;
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
        classes.push_back(CasterClass::from_name(class_str));
	}
	b.set_classes(classes);

	// Get the subclasses
	std::vector<Subclass> subclasses;
    Json::Value subclassesJSON = root[subclasses_k];
    subclasses.reserve(subclassesJSON.size());
	for (const auto& v : subclassesJSON) {
		subclasses.push_back(enum_from_name<Subclass>(subclassNames, v[name_k].asString()));
	}
	b.set_subclasses(subclasses);

	Spell spell = b.build_and_reset();
    return spell;

}

} // end namespace DnD