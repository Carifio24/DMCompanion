#ifndef FRACTION_H
#define FRACTION_H

#include <string>

namespace DnD {

class Fraction {

public:

    // Constructors
    Fraction(int n, int d);
    Fraction(int n) : Fraction(n, 1) {}

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

    int gcd(int a, int b) const;
};

} // end namespace DnD

#endif // FRACTION_H

