#include "rational.hpp"

int
main()
{
    rational r { 10, 4 };
    r *= r;
    std::cout << r << '\n';
    return 0;
}
