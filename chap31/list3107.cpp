/** Listing 31-7. Arithmetic Operators for the rational Type */
#include "rational_class.hpp"
#include <iostream>

int
main()
{
    rational a { 1, 2 };
    rational b { 1, 3 };
    rational c { 1, 4 };
    rational d { 1, 6 };
    rational e { 1 };
    rational f { 2 };
    rational g { 3 };

    if (not(e - a == a)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(e - a == a)" << "\n";
    }
    if (not(g - e == f)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(g - e == f)" << "\n";
    }
    if (not(a * b == d)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(a * b == d)" << "\n";
    }
    if (not(a * f == e)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(a * f == e)" << "\n";
    }
    if (not(c * f == a)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(c * f == a)" << "\n";
    }
    if (not(e / g == b)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(e / g == b)" << "\n";
    }
    if (not(f / g == b + b)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(f / g == b + b)" << "\n";
    }

    return 0;
}
