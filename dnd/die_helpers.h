#ifndef DIE_HELPERS_H
#define DIE_HELPERS_H

#include "enumerations.h"
#include <string>
#include <vector>

namespace DnD {

std::vector<int> roll_die(const Die& d, const int n);
int roll_die(const Die& d);
float average(const Die& d);
std::string name(const Die& d);

Die d(const int n);

} // end namespace DnD

#endif