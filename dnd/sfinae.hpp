#include <type_traits>

// For extracting the return type of operator[]
// First, we use std::declval<int>() to generate a dummy int&& (this is overkill, since we could easily construct a test int, but whatever)
// Then, we create a dummy IntSS&&, and use decltype to see what the return type would be
// We need std::remove_reference_t since operator[] will (most likely) return a reference, which we don't want

template <typename IntSS>
struct intss {
    using type = std::remove_reference_t<decltype(std::declval<IntSS>()[std::declval<int>()])>;
};

template <typename IntSS>
using intss_t = typename intss<IntSS>::type;