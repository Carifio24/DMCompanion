#include "profile.h"

#include <fstream>

#include "json/json.h"

bool Profile::is_favorite(const DnD::Spell& spell) const {
    return std::find(_fav_spells.begin(), _fav_spells.end(), spell.name()) != _fav_spells.end();
}

void Profile::set_favorite_status(const DnD::Spell& s, bool b) {
    bool fav = is_favorite(s);
    if (b == fav) { return; } // If the status to set to is the same as the current one, do nothing
    if (b) {
        _fav_spells.insert(s.name());
    } else {
        _fav_spells.erase(s.name());
    }
}

void Profile::set_favorite(const DnD::Spell& s) { set_favorite_status(s, true); }
void Profile::remove_favorite(const DnD::Spell& s) { set_favorite_status(s, false); }
void Profile::toggle_favorite(const DnD::Spell& s) {
    set_favorite_status(s, !is_favorite(s));
}


Profile Profile::load(const std::string& filename) {
    std::ifstream ifs{filename};
}
