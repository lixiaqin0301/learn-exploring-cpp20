#include "rat3.hpp"
#include <iostream>
int
main()
{
    rational r { 2, 4 };
    std::cout << r.numerator() << '/' << r.denominator() << '\n';
}
