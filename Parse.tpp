#ifndef PARSE_T
#define PARSE_T

#include <vector>
#include <algorithm>
#include <assert.h>
#include <jsoncpp/json/json.h>

#include <iostream>

template <class T>
int get_index(const std::vector<T>& v, const T& x) {
    auto it = std::find(v.begin(), v.end(), x);
    std::cout << x << std::endl;
    std::cout << std::distance(v.begin(), it) << std::endl;
    assert(it != v.end());
    return std::distance(v.begin(), it);
}

template <class Enum>
Enum enum_from_names(const std::vector<std::string>& allNames, const std::string& name) {
    std::cout << name << std::endl;
	return static_cast<Enum>(get_index(allNames, name));
}

template <class Enum>
Enum enum_from_name(const std::map<Enum,std::string>& namesMap, const std::string& name) {
    auto it = std::find_if(namesMap.begin(), namesMap.end(), [name](const auto& x) -> bool { return x.second == name; } );
    assert(it != namesMap.end());
    return it->first;
}

template <class Enum>
std::vector<Enum> enum_vector_from_names(const auto& allNames, const std::vector<std::string>& names) {
    std::vector<Enum> enums;
    enums.reserve(names.size());
    for (size_t i = 0; i < enums.size(); i++) {
        enums.push_back(enum_from_name<Enum>(allNames, names[i]));
    }
    return enums;
}


// T here must be constructible from a Json::Value object
template <class T>
std::vector<T> json_array_to_vector(const Json::Value& array) {
    std::vector<T> res(array.size());
    int i = 0;
    for (const auto& v : array) {
        res[i++] = T(v);
    }
    return res;
}

#endif
