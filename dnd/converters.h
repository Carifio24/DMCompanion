#ifndef CONVERTERS_H
#define CONVERTERS_H

#include "enumerations.h"
#include <string>

namespace DnD {

bool yn_to_bool(const std::string& yn);
std::string bool_to_yn(const bool& yn);

} // end namespace DnD

#endif