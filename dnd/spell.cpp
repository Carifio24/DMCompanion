#include "spell.h"
#include "string_helpers.h"

#include <string>
#include <sstream>

namespace DnD {

std::string Spell::components_string() const {
    std::string s;
    if (_components[0]) { s += "V"; }
    if (_components[1]) { s += "S"; }
    if (_components[2]) { s += "M"; }
    return s;
}

std::string Spell::classes_string() const {
    std::vector<std::string> class_names;
    class_names.reserve(_classes.size());
    for (auto x : _classes) {
        class_names.emplace_back(x.get().name());
    }
    std::string class_s = join(class_names, ", ");
    return class_s;
}

bool Spell::usable_by(const CasterClass& cc) const {
    for (auto x : _classes) {
        if (x == cc) {
            return true;
        }
    }
    return false;
}

std::string Spell::school_level_string() const {
    std::stringstream ss;
    switch (_level) {
        case 0:
            ss << _school.name() << " cantrip"; break;
        case 1:
            ss << "1st"; break;
        case 2:
            ss << "2nd"; break;
        case 3:
            ss << "3rd"; break;
        default:
            ss << std::to_string(_level) << "th"; break;
    }

    if (_level > 0) {
        std::string school_name(_school.name());
        to_lowercase(school_name);
        ss << "-level " << school_name;
    }

    if (_ritual) {
        ss << " (ritual)";
    }

    return ss.str();

}

} // end namespace DnD