/** Listing 31-11. Computing the Absolute Value of a Rational Number */
#include "rational_class.hpp"
#include <iostream>

int
main()
{
    rational r { -1, 2 };
    auto absr { absval(r) };
    std::cout << absr.numerator << '/' << absr.denominator << '\n';
    return 0;
}
