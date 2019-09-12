#ifndef SCHOOL_H
#define SCHOOL_H

#include "named_enum.hpp"

namespace DnD {

class SchoolImpl : public NamedEnumImpl<SchoolImpl> {

    public:

        // The class instances
        struct Instances;

        // Get the character that represents the school
        inline constexpr char character() const noexcept { return _character; }

        // Create an instance from a character
        static const SchoolImpl& from_character(char c) {
            const std::function<void(char&)> make_upper = [](char& c) { return std::toupper(c); };
            return from_member(c, &SchoolImpl::character, make_upper);
        }


    private:

        // Constructor
        constexpr SchoolImpl(std::string_view name, char c) : NamedEnumImpl<SchoolImpl>(name), _character(c) {}

        // Member values
        const char _character;

};

struct SchoolImpl::Instances {
    static inline constexpr const SchoolImpl Abjuration{"Abjuration", 'A'};
    static inline constexpr const SchoolImpl Conjuration{"Conjuration", 'C'};
    static inline constexpr const SchoolImpl Divination{"Divination", 'D'};
    static inline constexpr const SchoolImpl Enchantment{"Enchantment", 'E'};
    static inline constexpr const SchoolImpl Evocation{"Evocation", 'V'};
    static inline constexpr const SchoolImpl Illusion{"Illusion", 'I'};
    static inline constexpr const SchoolImpl Necromancy{"Necromancy", 'N'};
    static inline constexpr const SchoolImpl Transmutation{"Transmutation", 'T'};
    static inline constexpr const SchoolImpl* const instances[] = { &Abjuration, &Conjuration, &Divination, &Enchantment, &Evocation, &Illusion, &Necromancy, &Transmutation };
};

using Schools = SchoolImpl::Instances;

class School : public NamedEnum<SchoolImpl,School> {

    public:

        School(const SchoolImpl& si) : NamedEnum<SchoolImpl,School>(si) {}

        inline char character() const noexcept { return _impl.get().character(); }

        static School from_character(char c) { return School(SchoolImpl::from_character(c)); }

};

} // end namespace DnD


#endif