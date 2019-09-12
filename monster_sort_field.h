#ifndef MONSTER_SORT_FIELD_H
#define MONSTER_SORT_FIELD_H

#include "sort.hpp"
#include "dnd/monster.h"
#include "dnd/named_enum.hpp"

class MonsterSortFieldImpl : public NamedEnumImpl<MonsterSortFieldImpl> {

    public:
        struct Instances;

    private:
        constexpr MonsterSortFieldImpl(std::string_view name) : NamedEnumImpl<MonsterSortFieldImpl>(name) {}
};

struct MonsterSortFieldImpl::Instances {
    static inline constexpr const MonsterSortFieldImpl Name{"Name"};
    static inline constexpr const MonsterSortFieldImpl Size{"Size"};
    static inline constexpr const MonsterSortFieldImpl Type{"Type"};
    static inline constexpr const MonsterSortFieldImpl HitPoints{"Hit points"};
    static inline constexpr const MonsterSortFieldImpl ArmorClass{"Armor class"};
    static inline constexpr const MonsterSortFieldImpl Strength{"Strength"};
    static inline constexpr const MonsterSortFieldImpl Dexterity{"Dexterity"};
    static inline constexpr const MonsterSortFieldImpl Constitution{"Constitution"};
    static inline constexpr const MonsterSortFieldImpl Intelligence{"Intelligence"};
    static inline constexpr const MonsterSortFieldImpl Wisdom{"Wisdom"};
    static inline constexpr const MonsterSortFieldImpl Charisma{"Charisma"};
    static inline constexpr const MonsterSortFieldImpl* const instances[] = { &Name, &Size, &Type, &HitPoints, &ArmorClass, &Strength, &Dexterity, &Constitution, &Intelligence, &Wisdom, &Charisma };
};

using MonsterSortFields = MonsterSortFieldImpl::Instances;

class MonsterSortField : public NamedEnum<MonsterSortFieldImpl,MonsterSortField> {

    public:

        // Constructor
        MonsterSortField(const MonsterSortFieldImpl& msfi) : NamedEnum<MonsterSortFieldImpl,MonsterSortField>(msfi) {}

        // Get the tri-comparator function
        BinaryIntFunc<DnD::Monster> tricomparator() const noexcept {

            // Find the MonsterSortFieldImpl in the map
            auto it = monster_sort_TCs.find(_impl.get().index());

            // Get the tri-comparator from the iterator, falling back to name comparison if it wasn't found
            BinaryIntFunc<DnD::Monster> cmp = (it != monster_sort_TCs.end()) ? it->second : default_tricomparator();
            return cmp;
        }

        // Alias for the number of monster sort fields
        static inline constexpr int n_fields() noexcept { return n_values(); }

        // Default sort field
        static inline MonsterSortField default_field() noexcept { return MonsterSortField(Name); }
        static inline BinaryIntFunc<DnD::Monster> default_tricomparator() noexcept { return default_field().tricomparator(); }

    private:

        // Map of the tri-comparator functions for each sort field
        inline static const std::map<int, BinaryIntFunc<DnD::Monster>> monster_sort_TCs = {
            { Name.index(), test_less_equal(&DnD::Monster::name) },
            { Size.index(), test_less_equal(&DnD::Monster::size) },
            { Type.index(), test_less_equal(&DnD::Monster::type) },
            { HitPoints.index(), test_less_equal(&DnD::Monster::hit_points) },
            { ArmorClass.index(), test_less_equal(&DnD::Monster::armor_class) },
            { Strength.index(), test_less_equal(&DnD::Monster::strength) },
            { Dexterity.index(), test_less_equal(&DnD::Monster::dexterity) },
            { Constitution.index(), test_less_equal(&DnD::Monster::constitution) },
            { Intelligence.index(), test_less_equal(&DnD::Monster::intelligence) },
            { Wisdom.index(), test_less_equal(&DnD::Monster::wisdom) },
            { Charisma.index(), test_less_equal(&DnD::Monster::charisma) }
        };

};

#endif // MONSTER_SORT_FIELD_H
