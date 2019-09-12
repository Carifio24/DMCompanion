#ifndef SORT_H
#define SORT_H

#include <map>
#include <vector>
#include <string>

#include "dnd/spell.h"

// Template implementations
#include "sort.tpp"

inline static const std::map<std::string, std::function<int(const DnD::Spell&, const DnD::Spell&)> > spell_sort_fns = {
    { "Level", test_less_equal(&DnD::Spell::level) },
    { "Name", test_less_equal(&DnD::Spell::name) },
    { "School", test_less_equal(&DnD::Spell::school) },
};
inline static const std::string default_spell_field = "Name";
inline static const std::string none_field = "None";

inline static const std::vector<std::string> spell_sort_fields = { "Name", "Level", "School" };
inline static const size_t n_sortable = spell_sort_fields.size();

#endif
