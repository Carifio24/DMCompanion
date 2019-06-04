#include "Converters.h"

#include <stdexcept>

bool yn_to_bool(const std::string& yn) {
	if (yn == "no") {
		return false;
	}
	else if (yn == "yes") {
		return true;
	}
	else {
		throw std::runtime_error("Invalid yes/no entry");
	}
}

std::string bool_to_yn(const bool& yn) {
	if (yn) {
		return "yes";
	} else {
		return "no";
	}
}