/** Listing 31-6. Addition Operator for the rational Type */
#include "rational_class.hpp"
#include <iostream>

int
main()
{
    rational a { 1, 2 };
    rational b { 1 };
    rational c { -1, 2 };

    if (not(a + a == b)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(a + a == b)" << "\n";
    }
    if (not(-a == c)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(-a == c)" << "\n";
    }
    if (not(a == -(-a))) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(a == -(-a))" << "\n";
    }

    return 0;
}
