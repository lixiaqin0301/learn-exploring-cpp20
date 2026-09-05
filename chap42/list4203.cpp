/** Listing 42-3. Defining the rational Class In a Module */
#include "rat1.hpp"
#include <iostream>

int
main()
{
    rational r { 2, 4 };
    std::cout << r.numerator() << '/' << r.denominator() << '\n';
    return 0;
}
