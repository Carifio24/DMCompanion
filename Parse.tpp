#ifndef PARSE_T
#define PARSE_T

#include <vector>

template <class T>
int get_index(const std::vector<T>& v, const T& x) {
	auto it = std::find(v.begin(), v.end(), x);
	return it - v.begin();
}

template <class Enum>
Enum enum_from_name(const std::vector<std::string> allNames, const std::string& name) {
	return static_cast<Enum>(get_index(allNames, name));
}

#endif