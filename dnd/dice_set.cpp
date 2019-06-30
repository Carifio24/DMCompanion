#include "dice_set.h"
#include "die_helpers.h"
#include "string_helpers.h"

#include <vector>
#include <sstream>

namespace DnD {

int DiceSet::roll() const noexcept {
    int sum = 0;
    for (auto it = _dmap.cbegin(); it != _dmap.cend(); ++it) {
        Die d = it->first;
        int n = it->second;
        std::vector<int> v = roll_die(d, n);
        for (const auto& x : v) {
            sum += x;
        }
    }
    return sum;
}

float DiceSet::average_value() const noexcept {
    float avg = 0;
    for (auto it = _dmap.cbegin(); it != _dmap.cend(); ++it) {
        avg += it->second * average(it->first);
    }
    return avg;
}

std::string DiceSet::as_string() const noexcept {
    if (_dmap.size() == 0) { return ""; }
    std::stringstream ss;
    auto it = _dmap.cbegin();
    ss << it->second << "d" << *it->first;
    ++it;
    for (; it != _dmap.cend(); ++it) {
        ss << " + " << it->second << "d" << *it->first;
    }
    return ss.str();
}

DiceSet DiceSet::from_string(std::string s) {
    std::map<Die, int> dmap;
    std::vector<std::string> dice_strs = split(s, " + ");
    for (std::string ds : dice_strs) {
        std::vector<std::string> data = split(ds, "d");
        int num = std::stoi(data[0]);
        int dval = std::stoi(data[1]);
        dmap.insert(std::make_pair(d(dval),num));
    }
    DiceSet dset(dmap);
    return dset;
}

} // end namespace DnD