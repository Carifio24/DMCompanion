#ifndef ENUM_HELPERS_HPP
#define ENUM_HELPERS_HPP

#include <type_traits>

namespace DnD {

// For convenience, and to keep the code cleaner, we overload the dereferencing operator to get the value of an enum
// So when you see something like *Tiny in the code, it's just getting the value of Tiny (i.e., 0)
// This is mostly useful for enums where the value is actually meaningful (i.e. Die), but it's a nice option to have regardless
// This is accomplished by casting the enum to its underlying type (note that the underlying type is declared for all of our enums)
template <typename T>
constexpr decltype(auto) operator*(T e) noexcept {
    return static_cast<std::underlying_type_t<T>>(e);
}

}

#endif