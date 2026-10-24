/** Listing 51-1. Writing an Absolute Value Function */
#include <iostream>

using T = int;

T
absval(T x)
{
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}

int
main()
{
    std::cout << absval(-1) << '\n';
}
