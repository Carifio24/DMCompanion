#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <sstream>
#include <algorithm>

#include "jstring.h"

namespace jstring {

	std::vector<std::string> split(std::string s, const std::string& dlm) {
		// This function splits the given string using the given delimiter
		// Returns a vector containing the pieces of the split string

		// Container to store split pieces
		std::vector<std::string> pieces;

		// Length of the delimiter
		int dlm_len = dlm.length();

		// While the delimiter still exists in the string, keep splitting off pieces
		size_t pos = 0;
		std::string piece;
		while ((pos=s.find(dlm)) != std::string::npos) {
			piece = s.substr(0, pos);
			pieces.push_back(piece);
			s.erase(0, pos + dlm_len);
		}

		pieces.push_back(s);
		return pieces;

	}

	std::vector<std::string> split_whitespace(const std::string& s) {
		// This function splits the given string by whitespace
		// Returns a vector containing the pieces of the split string
		std::vector<std::string> pieces;
		std::istringstream iss(s);
		while (iss) {
			std::string piece;
			iss >> piece;
			pieces.push_back(piece);
		}
		return pieces;

	}

	std::vector<std::string> split_multi(std::string s, const std::vector<std::string>& delims) {
		// This function splits the given string by all of the the given delimiters
		// Returns a vector containing the pieces of the split string

		// Container to store split pieces
		std::vector<std::string> pieces;
		pieces.push_back(s); // Start with the original string

		// Loop over the delimiters
		for (std::string dlm : delims) {

			// Loop over the current pieces, splitting each by the current delimiter
			std::vector<std::string> new_pieces;
			for (std::string piece : pieces) {
				std::vector<std::string> temp_pieces = split(piece, dlm);
				for (std::string x : temp_pieces) {
					new_pieces.push_back(x);
				}
			}
			pieces = new_pieces;
			}

		return pieces;
	}


	std::string join(const std::vector<std::string>& v, const std::string& s) {
		// This function joins the vector v using the string s
		// i.e. so join({"Two","words"}, " ") outputs "Two words"
		std::string res;
		for (unsigned int i = 0; i < v.size()-1; i++) {
			res += v[i];
			res += s;
		}
		res += v[v.size()-1];
		return res;
	}


	bool endswith(const std::string& s, const std::string& end) {
		if (end.size() > s.size()) {return false;}
		return std::equal(end.rbegin(), end.rend(), s.rbegin());
	}


	std::string dir_up_one(std::string dirname, const std::string fsep) {
		std::vector<std::string> folders = jstring::split(dirname, fsep);
		folders.erase(folders.end()-1);
		return jstring::join(folders, fsep);
	}
}
