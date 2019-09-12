#ifndef PROFILE_H
#define PROFILE_H

#include <set>
#include <string>

#include "dnd/spell.h"


class Profile {
    public:
        Profile() {}

        bool is_favorite(const DnD::Spell& s) const;
        void set_favorite_status(const DnD::Spell& s, bool b);
        void set_favorite(const DnD::Spell& s);
        void remove_favorite(const DnD::Spell& s);
        void toggle_favorite(const DnD::Spell& s);

        static Profile load(const std::string& filename);

   private:
        std::set<std::string> _fav_spells;
};

#endif // PROFILE_H
