#ifndef DIE_HELPERS_H
#define DIE_HELPERS_H

#include "Enumerations.h"
#include <string>

namespace DnD {

std::vector<int> roll_die(const Die& d, const int& n);
int roll_die(const Die& d);
std::string name(const Die& d);

} // end namespace DnD

#endif