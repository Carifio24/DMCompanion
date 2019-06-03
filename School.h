#ifndef SCHOOL_H
#define SCHOOL_H

#include "NamedEnum.h"

namespace DnD {

class School : public NamedEnum<School> {

    public:

        // The class instances
        struct Instances;

        // Get the character that represents the school
        inline constexpr char character() const noexcept { return _character; }

        // Create an instance from a character
        static const School& from_character(char c) {
            const std::function<void(char&)> make_upper = [](char& c) { return std::toupper(c); };
            return from_member(c, &School::character, make_upper);
        }


    private:

        // Constructor
        constexpr School(const std::string_view& name, const char& c) : NamedEnum<School>(name), _character(c) {}

        // Member values
        const char _character;

};

struct School::Instances {
    static inline constexpr const School Abjuration{"Abjuration", 'A'};
    static inline constexpr const School Conjuration{"Conjuration", 'C'};
    static inline constexpr const School Divination{"Divination", 'D'};
    static inline constexpr const School Enchantment{"Enchantment", 'E'};
    static inline constexpr const School Evocation{"Evocation", 'V'};
    static inline constexpr const School Illusion{"Illusion", 'I'};
    static inline constexpr const School Necromancy{"Necromancy", 'N'};
    static inline constexpr const School Transmutation{"Transmutation", 'T'};
    static inline constexpr const School* const instances[] = { &Abjuration, &Conjuration, &Divination, &Enchantment, &Evocation, &Illusion, &Necromancy, &Transmutation };
};

using Schools = Schools::Instances;

} // end namespace DnD


#endif