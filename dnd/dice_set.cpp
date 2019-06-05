#include "dice_set.h"
#include "die_helpers.h"

#include <vector>

namespace DnD {

int DiceSet::roll() const noexcept {
    int sum = 0;
    for (auto it = _dice.begin(); it != _dice.end(); ++it) {
        Die d = it->first;
        int n = it->second;
        std::vector<int> v = roll_die(d, n);
        for (const auto& x : v) {
            sum += x;
        }
    }
    return sum;
}

} // end namespace DnD