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

    // Accessors
    int denominator() const noexcept { return den; }
    int numerator() const noexcept { return sgn * num; }
    bool is_positive() const noexcept { return (sgn > 0); }
    bool is_nonnegative() const noexcept { return (sgn >= 0); }
    bool is_negative() const noexcept { return (sgn < 0); }
    bool is_nonpositive() const noexcept { return (sgn <= 0); }
    bool is_zero() const noexcept { return (sgn == 0); }


    // Methods
    std::string as_string() const;
    bool is_integer() const;



private:
    int num;
    int den;
    int sgn;

    int gcd(int a, int b) const;
};


bool operator<(const Fraction& f1, const Fraction& f2);
bool operator==(const Fraction& f1, const Fraction& f2);

} // end namespace DnD

#endif // FRACTION_H

