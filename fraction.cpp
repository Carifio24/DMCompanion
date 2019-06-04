#include "fraction.h"
#include "jstring.h"

#include <iostream>
#include <vector>
#include <exception>
#include <assert.h>

// Constructors
Fraction::Fraction(const int& n, const int& d) {

    // Denominator can't be zero
    if (d == 0) {
        throw std::runtime_error("Denominator must be nonzero");
    }

    // If the numerator is zero, set the denominator to 1
    if (n == 0) {
        num = 0;
        den = 1;
        sgn = 0;
    } else {

        // Check the sign of the fraction
        sgn = ( (n > 0) ^ (d > 0) ) ? -1 : 1;
        num = std::abs(n);
        den = std::abs(d);

        // Find the GCD and reduce
        int g = gcd(num, den);
        num /= g;
        den /= g;
    }
}

Fraction Fraction::from_string(const std::string& s) {
    std::vector<std::string> num_den = jstring::split(s, "/");
    if (num_den.size() > 2) { throw std::runtime_error("Invalid string format for Fraction: " + s);}
    try {
        int n = std::stoi(num_den[0]);
        int d = (num_den.size() > 1) ? std::stoi(num_den[1]) : 1;
        return Fraction(n, d);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

// Return true if the fraction is an integer, false otherwise
bool Fraction::is_integer() const {
    return (den == 1);
}

// Print the fraction as a string
std::string Fraction::as_string() const {
    std::string s = std::to_string(sgn*num);
    if (!is_integer()) {
        s += "/" + std::to_string(den);
    }
    return s;
}

// GCD
int Fraction::gcd(const int& a, const int& b) const {
    return (b == 0) ? a : gcd(b, a % b);
}