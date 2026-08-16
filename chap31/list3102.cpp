/** Listing 31-2. Using inline for Trivial Functions */
#include "rational_class.hpp"

int
main()
{
    rational pi1 { 355, 113 };
    rational pi2 { 1420, 452 };

    if (pi1 == pi2) {
        std::cout << "success\n";
    } else {
        std::cout << "failure\n";
    }

    return 0;
}
