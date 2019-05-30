#include "StringHelpers.h"
#include <string>

bool starts_with(const std::string& test, const std::string& prefix) {
    if (test.length() < prefix.length()) { return false; }

    for (size_t i = 0; i < prefix.length(); ++i) {
        if (prefix[i] != test[i]) {
            return false;
        }
    }
    return true;
}