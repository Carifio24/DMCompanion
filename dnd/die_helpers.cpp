#include "die_helpers.h"
#include "string_helpers.h"
#include <random>

namespace DnD {

std::vector<int> roll_die(const Die& d, const int n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, *d);
    std::vector<int> results;
    results.reserve(n);
    for (int i = 0; i < n; ++i) {
        results.push_back(dist(gen));
    }
    return results;
}

int roll_die(const Die& d) {
    return roll_die(d, 1)[0];
}

float average(const Die& d) {
	return (*d + 1) / 2;
}

std::string name(const Die& d) {
    std::string s = "d" + std::to_string(*d);
    return s;
}

Die d(const int n) {
	switch(n) {
		case 4:
			return Die::d4;
		case 6:
			return Die::d6;
		case 8:
			return Die::d8;
		case 10:
			return Die::d10;
		case 12:
			return Die::d12;
		case 20:
			return Die::d20;
		default:
			return Die::d6; // Unreachable, switch exhausts Die enum

	}
}

} // end namespace DnD