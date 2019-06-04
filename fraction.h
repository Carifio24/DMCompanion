#ifndef FRACTION_H
#define FRACTION_H

#include <string>

class Fraction {

public:

    // Constructors
    Fraction(const int& n, const int& d);
    Fraction(const int& n) : Fraction(n, 1) {}

    // Default value is zero
    Fraction() : Fraction(0, 1) {}

    // Static methods
    static Fraction from_string(const std::string& s);


    // Methods
    std::string as_string() const;
    bool is_integer() const;


private:
    int num;
    int den;
    int sgn;

    int gcd(const int& a, const int& b) const;
};

#endif // FRACTION_H
