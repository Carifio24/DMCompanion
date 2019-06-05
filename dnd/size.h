#ifndef SIZE_H
#define SIZE_H

#include "named_enum.hpp"

namespace DnD {

class Size : public NamedEnum<Size> {

    public:
        struct Instances;

    private:
        constexpr Size(const std::string_view& name) : NamedEnum<Size>(name) {}

};

struct Size::Instances {
    static inline constexpr const Size Tiny{"Tiny"};
    static inline constexpr const Size Small{"Small"};
    static inline constexpr const Size Medium{"Medium"};
    static inline constexpr const Size Large{"Large"};
    static inline constexpr const Size Huge{"Huge"};
    static inline constexpr const Size Gargantuan{"Gargantuan"};
    static inline constexpr const Size* const instances[] = { &Tiny, &Small, &Medium, &Large, &Huge, &Gargantuan };
};

using Sizes = Size::Instances;


} // end namespace DnD

#endif