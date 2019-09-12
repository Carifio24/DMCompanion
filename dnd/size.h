#ifndef SIZE_H
#define SIZE_H

#include "named_enum.hpp"

namespace DnD {

class SizeImpl : public NamedEnumImpl<SizeImpl> {

    public:

        // The class instances
        struct Instances;

        // Get the length of a side
        inline constexpr float side_length() const noexcept { return _side; }

    private:

        // Constructor
        constexpr SizeImpl(std::string_view name, float side) : NamedEnumImpl<SizeImpl>(name), _side(side) {}
        
        // Length taken up each dimension
        const float _side;

};

struct SizeImpl::Instances {
    static inline constexpr const SizeImpl Tiny{"Tiny"sv, 2.5};
    static inline constexpr const SizeImpl Small{"Small"sv, 5};
    static inline constexpr const SizeImpl Medium{"Medium"sv, 5};
    static inline constexpr const SizeImpl Large{"Large"sv, 10};
    static inline constexpr const SizeImpl Huge{"Huge"sv, 15};
    static inline constexpr const SizeImpl Gargantuan{"Gargantuan"sv, 20};
    static inline constexpr const SizeImpl* const instances[] = { &Tiny, &Small, &Medium, &Large, &Huge, &Gargantuan };
};

using Sizes = SizeImpl::Instances;

class Size : public NamedEnum<SizeImpl,Size> {

    public:
        Size(const SizeImpl& si) : NamedEnum<SizeImpl,Size>(si) {}

        inline float side_length() const noexcept { return _impl.get().side_length(); }

};


} // end namespace DnD

#endif