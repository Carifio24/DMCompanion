#ifndef JSTRING_H
#define JSTRING_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <sstream>
#include <algorithm>

namespace jstring {

	std::vector<std::string> split(std::string s, const std::string& dlm);

	std::vector<std::string> split_whitespace(const std::string& s);

	std::vector<std::string> split_multi(std::string s, const std::vector<std::string>& delims);

	std::string join(const std::vector<std::string>& v, const std::string& s);

	bool endswith(const std::string& s, const std::string& end);

	std::string dir_up_one(std::string dirname, const std::string fsep="/");


	template <class T>
	std::string tostring(const T& t) {
		std::ostringstream ss;
		ss << t;
		return ss.str();
	}

	template <class T>
	T fromstring(const std::string& s) {
		std::istringstream ss(s);
		T t;
		ss >> t;
		return t;
	}


}

#endif

/*
int main() {
	// For testing the functions
	std::string test = "Let's:see,if:this;works";
	std::vector<std::string> delims = {":", ",", ";"};
	std::vector<std::string> result = split_multi(test, delims);
	for (std::string s : result) {
		std::cout << s << "\n";
	}
}*/