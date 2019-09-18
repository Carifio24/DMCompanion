#include "qhelpers.h"

#include <algorithm>
#include <QStringBuilder>

#include <boost/algorithm/string/replace.hpp>

std::string snake_case_format(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) -> unsigned char { return std::tolower(c); });
    boost::replace_all(s, " ", "_");
    return s;
}
