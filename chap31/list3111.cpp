#include "rational.hpp"

#include "list3111.hh"
#include <cmath>
int
main()
{
    rational r { -1, 2 };
    auto absr { absval(r) };
    std::cout << absr.numerator << '/' << absr.denominator << '\n';
}
