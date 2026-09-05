/** Listing 42-4. Defining the rational Class In One Declaration In a Module */
#include "rat2.hpp"
#include <iostream>

int
main()
{
    rational r { 2, 4 };
    std::cout << r.numerator() << '/' << r.denominator() << '\n';
    return 0;
}
