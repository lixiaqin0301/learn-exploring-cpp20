#include "rational.hpp"

int
main()
{
    rational r1 { 1, 2 };

    r1 += rational { 1, 3 };
    r1 /= rational { 2, 3 };
    r1 -= rational { 1, 4 };
    std::cout << r1 << '\n';

    return 0;
}
