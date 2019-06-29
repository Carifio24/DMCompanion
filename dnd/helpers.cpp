#include "helpers.h"
#include <cmath>

namespace DnD {

int modifier(int score) {
    return static_cast<int>(std::floor((score - 10) / 2));
}

} // end namespace DnD