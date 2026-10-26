#include "rational.hpp"

int
main()
{
    rational n { 710 };
    rational d { 226 };
    n /= d;
    std::cout << n << '\n';
}
