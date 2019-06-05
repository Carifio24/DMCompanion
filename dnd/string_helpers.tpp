#ifndef STRING_HELPERS_TPP
#define STRING_HELPERS_TPP

#include "sfinae.hpp"

#include <string>

namespace DnD {

// We only allow this to be instantiated if operator[int] yields a char
template <typename T, typename = std::enable_if_t<std::is_same_v<intss_t<T>,char>>>
bool starts_with(const std::string& test, const T& prefix) {
    if (test.length() < prefix.length()) { return false; }

    for (size_t i = 0; i < prefix.length(); ++i) {
        if (prefix[i] != test[i]) {
            return false;
        }
    }
    return true;
}

// We only allow this to be instantiated if operator[int] yields a char
template <typename T, typename = std::enable_if_t<std::is_same_v<intss_t<T>,char>>>
bool ends_with(const std::string& test, const T& prefix) {
    if (test.length() < prefix.length()) { return false; }

    for (size_t i = test.size()-1; i >= 0; --i) {
        if (prefix[i] != test[i]) {
            return false;
        }
    }
    return true;
}

} // end namespace DnD

#endif