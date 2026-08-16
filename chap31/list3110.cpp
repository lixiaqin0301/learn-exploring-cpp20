/** Listing 31-10. Optimizing Operators for a Specific Operand Type */
#include "rational_class.hpp"
#include <iostream>

int
main()
{
    rational pi { 355, 113 };
    rational pi2 { 2 * pi };
    rational pi4 { 4 * pi };
    std::cout << pi2.numerator << '/' << pi2.denominator << '\n';
    std::cout << pi4.numerator << '/' << pi4.denominator << '\n';
    return 0;
}
