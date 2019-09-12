#include "json_helpers.h"

namespace DnD {

int int_if_member(const Json::Value& root, const std::string& field, const int defaultValue) {
    return root.isMember(field) ? root[field].asInt() : defaultValue;
}

std::string string_if_member(const Json::Value& root, const std::string& field, const std::string& defaultValue) {
    return root.isMember(field) ? root[field].asString() : defaultValue;
}

} // end namespace DnD
