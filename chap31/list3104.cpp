/** Listing 31-4. Implementing the > and >= Operators in Terms of < */
#include "rational_class.hpp"
#include <iostream>

int
main()
{
    rational pi1 { 355, 113 };
    rational pi2 { 1420, 452 };

    if (pi1 >= pi2 and pi2 >= pi1) {
        std::cout << "success\n";
    } else {
        std::cout << "failure\n";
    }

    return 0;
}
