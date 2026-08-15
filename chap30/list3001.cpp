/** Listing 30-1. Defining a Custom rational Type */
/// Represent a rational number.

#include <iostream>

struct rational {
    int numerator;   ///< numerator gets the sign of the rational value
    int denominator; ///< denominator is always positive
};

int
main()
{
    struct rational r = { 1, 2 };
    std::cout << "r={" << r.numerator << '/' << r.denominator << "}\n";
    return 0;
}
