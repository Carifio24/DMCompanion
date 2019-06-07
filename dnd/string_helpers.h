#ifndef STRING_HELPERS_H
#define STRING_HELPERS_H

#include <string>
#include <vector>

namespace DnD {

bool starts_with(const std::string& s, const char* cstr);
bool ends_with(const std::string& s, const char* cstr);
std::vector<std::string> split(std::string s, const std::string& dlm, int n_pieces=-1);
std::string join(const std::vector<std::string>& pieces, const std::string& dlm);
void to_lowercase(std::string& s);
std::string lowercase(const std::string& s);

// Template functions
#include "string_helpers.tpp"

} // end namespace DnD

#endif