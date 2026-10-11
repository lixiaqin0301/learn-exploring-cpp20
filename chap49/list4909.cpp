#include "rational.hpp"
#include <iostream>

int
main()
{
    rational r { 1, 2 };
    std::cout << r++ << '\n';
    std::cout << r-- << '\n';
    std::cout << r << '\n';
    return 0;
}
