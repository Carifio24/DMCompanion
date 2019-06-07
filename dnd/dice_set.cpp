#include "dice_set.h"
#include "die_helpers.h"

#include <vector>

namespace DnD {

int DiceSet::roll() const noexcept {
    int sum = 0;
    for (auto it = _dmap.begin(); it != _dmap.end(); ++it) {
        Die d = it->first;
        int n = it->second;
        std::vector<int> v = roll_die(d, n);
        for (const auto& x : v) {
            sum += x;
        }
    }
    return sum;
}

DiceSet from_string(std::string s) {
    
}

} // end namespace DnD