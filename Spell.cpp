#include "Spell.h"

std::string Spell::componentsText() {
    std::string s;
    if (components[0]) { s += "V"; }
    if (components[1]) { s += "S"; }
    if (components[2]) { s += "M"; }
}
