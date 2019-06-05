#include "spell.h"
#include "string_helpers.h"

#include <string>

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
        class_names.emplace_back(x->name());
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
