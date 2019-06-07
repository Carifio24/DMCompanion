#include "duration.h"

namespace DnD {

bool Duration::operator==(const Duration& other) const noexcept {
    return time_in_seconds() == other.time_in_seconds();
}

} // end namespace DnD