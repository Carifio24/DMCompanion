#ifndef JSON_HELPERS_H
#define JSON_HELPERS_H

#include <json/json.h>
#include <string>

namespace DnD {

int int_if_member(const Json::Value& root, const std::string& field, int defaultValue=0);

std::string string_if_member(const Json::Value& root, const std::string& field, const std::string& defaultValue="");

} // end namespace DnD

#endif
