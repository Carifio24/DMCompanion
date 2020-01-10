#ifndef SPELL_SORT_FIELD_H
#define SPELL_SORT_FIELD_H

#include <map>

#include "sort.hpp"
#include "dnd/spell.h"
#include "dnd/named_enum.hpp"

class SpellSortFieldImpl : public NamedEnumImpl<SpellSortFieldImpl> {

    public:
        struct Instances;

    private:
        constexpr SpellSortFieldImpl(std::string_view name) : NamedEnumImpl<SpellSortFieldImpl>(name) {}

};

struct SpellSortFieldImpl::Instances {
    static inline constexpr const SpellSortFieldImpl Name{"Name"};
    static inline constexpr const SpellSortFieldImpl Level{"Level"};
    static inline constexpr const SpellSortFieldImpl School{"School"};
    static inline constexpr const SpellSortFieldImpl Range{"Range"};
    static inline constexpr const SpellSortFieldImpl Duration{"Duration"};
    static inline constexpr const SpellSortFieldImpl* const instances[] = { &Name, &Level, &School, &Range, &Duration };
};

using SpellSortFields = SpellSortFieldImpl::Instances;

class SpellSortField : public NamedEnum<SpellSortFieldImpl,SpellSortField> {


    public:

        // Constructor
        SpellSortField(const SpellSortFieldImpl& ssfi) : NamedEnum<SpellSortFieldImpl,SpellSortField>(ssfi) {}

        // Get the tri-comparator function, reversed if desired
        BinaryIntFunc<DnD::Spell> tricomparator(const bool reverse=false) const noexcept {

            // Find the SpellSortFieldImpl in the map
            auto it = spell_sort_TCs.find(_impl.get().index());

            // Get the tri-comparator from the iterator, falling back to name comparison if it wasn't found
            BinaryIntFunc<DnD::Spell> cmp = (it != spell_sort_TCs.end()) ? it->second : default_tricomparator();
            int reverse_sign = reverse ? -1 : 1;
            return [reverse_sign, cmp](const DnD::Spell& t1, const DnD::Spell& t2) { return reverse_sign * cmp(t1,t2); };
        }

        // Alias for the number of spell sort fields
        static inline constexpr int n_fields() noexcept { return n_values(); }

        // Default sort field
        static inline SpellSortField default_field() noexcept { return SpellSortField(Name); }
        static inline BinaryIntFunc<DnD::Spell> default_tricomparator() noexcept { return default_field().tricomparator(); }

    private:

            // Map of the tri-comparator functions for each sort field
            inline static const std::map<int, BinaryIntFunc<DnD::Spell>> spell_sort_TCs = {
                { Name.index(), test_less_equal(&DnD::Spell::name) },
                { Level.index(), test_less_equal(&DnD::Spell::level) },
                { School.index(), test_less_equal(&DnD::Spell::school) },
                { Range.index(), test_less_equal(&DnD::Spell::range) },
                { Duration.index(), test_less_equal(&DnD::Spell::duration) }
            };

};


#endif // SPELL_SORT_FIELD_H
