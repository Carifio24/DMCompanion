#include <string>

#include "SpellParse.h"

namespace DnD {

// Spellbook-specific methods

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

Spell parse_spell(const Json::Value& root, const SpellBuilder& b) {

	// Create the spell and get the basic info
    b.set_name(root["name"].asString());
    std::vector<std::string> pdata = split(root["page"].asString(), " ", 2);
    b.set_page(std::stoi(pdata[1]));
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

} // end namespace DnD