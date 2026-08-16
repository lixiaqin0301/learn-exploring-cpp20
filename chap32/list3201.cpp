/** Listing 32-1. Input Operator */
#include "rational_class.hpp"
#include <iostream>

int
main()
{
    rational r { 1, 2 };
    std::cout << "r = " << r << '\n';
    return 0;
}
