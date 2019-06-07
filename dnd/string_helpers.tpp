#ifndef STRING_HELPERS_TPP
#define STRING_HELPERS_TPP

#include "sfinae.hpp"

#include <string>

// Note that we don't need to wrap everything in 'namespace DnD'
// As this file will be #include'd in string_helpers.h

// We only allow this to be instantiated if operator[int] yields a char
//template <typename T, typename = std::enable_if_t<std::is_same_v<std::remove_cv_t<intss_t<T>>,char>>>
template <typename T>
bool starts_with(const std::string& test, T&& prefix) {
    if (test.length() < prefix.length()) { return false; }

    static_assert(std::is_same_v<std::remove_cv_t<intss_t<T>>,char>);
    for (size_t i = 0; i < prefix.length(); ++i) {
        if (prefix[i] != test[i]) {
            return false;
        }
    }
    return true;
}

// We only allow this to be instantiated if operator[int] yields a char
//template <typename T, typename = std::enable_if_t<std::is_same_v<std::remove_cv_t<intss_t<T>>,char>>>
template <typename T>
bool ends_with(const std::string& test, T&& prefix) {
    if (test.length() < prefix.length()) { return false; }

    static_assert(std::is_same_v<std::remove_cv_t<intss_t<T>>,char>);
    for (size_t i = test.size() - prefix.length(); i < test.size(); ++i) {
        if (prefix[i] != test[i]) {
            return false;
        }
    }
    return true;
}

#endif