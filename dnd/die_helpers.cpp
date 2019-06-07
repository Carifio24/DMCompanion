#include "die_helpers.h"
#include <random>

namespace DnD {

std::vector<int> roll_die(const Die& d, const int& n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, *d);
    std::vector<int> results;
    results.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        results.push_back(dist(gen));
    }
    return results;
}

int roll_die(const Die& d) {
    return roll_die(d, 1)[0];
}

std::string name(const Die& d) {
    std::string s = "d" + std::to_string(*d);
    return s;
}

} // end namespace DnD