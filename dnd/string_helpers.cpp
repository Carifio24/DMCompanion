#include "string_helpers.h"

#include <cctype>
#include <sstream>
#include <algorithm>

namespace DnD {

std::vector<std::string> split(std::string s, const std::string& dlm, int n_pieces) {
    // This function splits the given string using the given delimiter
    // Returns a vector containing the pieces of the split string

    // If a max size wasn't explicitly set, then we can have at max s.size() pieces
    if (n_pieces < 0) {
        n_pieces = s.size();
    }

    // Container to store split pieces
    std::vector<std::string> pieces;

    // Length of the delimiter
    int dlm_len = dlm.length();

    // While the delimiter still exists in the string, keep splitting off pieces
    size_t pos = 0;
    std::string piece;
    while ( ((pos=s.find(dlm)) != std::string::npos) && (pieces.size() < n_pieces) ) {
        piece = s.substr(0, pos);
        pieces.push_back(piece);
        s.erase(0, pos + dlm_len);
    }

    pieces.push_back(s);
    return pieces;

}

std::string join(const std::vector<std::string>& pieces, const std::string& dlm) {
    std::stringstream ss;
    ss << pieces[0];
    for (size_t i = 1; i < pieces.size(); ++i) {
        ss << dlm << pieces[i];
    }
    std::string s = ss.str();
    return s;
}

void to_lowercase(std::string& s) {
    std::transform(s.begin(), s.end(), s.begin(), std::tolower);
}

std::string lowercase(const std::string& s) {
    std::string t;
    t.reserve(s.size());
    std::transform(s.begin(), s.end(), t.begin(), std::tolower);
}

std::string capitalized(std::string s) {
    char firstLetter = s[0];
    s[0] = std::toupper(firstLetter);
    return s;
}

} // end namespace DnD