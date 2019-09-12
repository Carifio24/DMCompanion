#include "string_helpers.h"

#include <cctype>
#include <cstring>
#include <sstream>
#include <algorithm>

namespace DnD {

bool string_match(const std::string& s1, const std::string& s2, const int start, const int finish) {
    for (int i = start; i < finish; ++i) {
        if (s1[i] != s2[i]) {
            return false;
        }
    }
    return true;
}

bool starts_with(const std::string& test, const char* prefix) {
    size_t pflen = strlen(prefix);
    if (test.length() < pflen) { return false; }

    for (size_t i = 0; i < pflen; ++i) {
        if (prefix[i] != test[i]) {
            return false;
        }
    }
    return true;
}

bool ends_with(const std::string& test, const char* suffix) {
    size_t pflen = strlen(suffix);
    if (test.length() < pflen) { return false; }

    int idx = 0;
    for (size_t i = test.size() - pflen; i < test.size(); ++i) {
        if (suffix[idx++] != test[i]) {
            return false;
        }
    }
    return true;
}

std::vector<std::string> split(std::string s, const std::string& dlm, size_t n_pieces) {
    // This function splits the given string using the given delimiter
    // Returns a vector containing the pieces of the split string

    // If a max size wasn't explicitly set, then we can have at max s.size() pieces
    if (n_pieces == 0) {
        n_pieces = s.size();
    }

    // Container to store split pieces
    std::vector<std::string> pieces;

    // Length of the delimiter
    const size_t dlm_len = dlm.length();

    // While the delimiter still exists in the string, keep splitting off pieces
    size_t pos = 0;
    std::string piece;
    while ( ((pos=s.find(dlm)) != std::string::npos) && (pieces.size() < n_pieces - 1) ) {
        piece = s.substr(0, pos);
        pieces.push_back(piece);
        s.erase(0, pos + dlm_len);
    }

    pieces.push_back(s);
    return pieces;

}

std::string join(const std::vector<std::string>& pieces, const std::string& dlm) {
    if (pieces.size() == 0) { return ""; }
    std::stringstream ss;
    ss << pieces[0];
    for (size_t i = 1; i < pieces.size(); ++i) {
        ss << dlm << pieces[i];
    }
    std::string s = ss.str();
    return s;
}

void to_lowercase(std::string& s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) -> unsigned char { return std::tolower(c); });
}

std::string lowercase(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) -> unsigned char { return std::tolower(c); });
    return s;
}

std::string capitalized(std::string s) {
    char firstLetter = s[0];
    s[0] = std::toupper(firstLetter);
    return s;
}

} // end namespace DnD