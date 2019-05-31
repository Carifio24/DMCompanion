#ifndef STRING_HELPERS_H
#define STRING_HELPERS_H

#include <string>
#include <vector>

namespace DnD {

bool starts_with(const std::string& test, const std::string& prefix);
bool ends_with(const std::string& test, const std::string& prefix);
std::vector<std::string> split(std::string s, const std::string& dlm, int n_pieces=-1);

} // end namespace DnD

#endif