#include "rational.hpp"
#include <iostream>

int
main()
{
    rational r { 1, 2 };
    ++r;
    std::cout << r << '\n';
    return 0;
}
