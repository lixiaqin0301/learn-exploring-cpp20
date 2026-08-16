/** @file list3105.cpp */
/** Listing 31-5. Testing the rational Comparison Operators */
#include "rational_class.hpp"
#include <iostream>

int
main()
{
    rational a { 60, 5 };
    rational b { 12, 1 };
    rational c { -24, -2 };
    if (not(a == b)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(a == b)" << "\n";
    }
    if (not(a >= b)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(a >= b)" << "\n";
    }
    if (not(a <= b)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(a <= b)" << "\n";
    }
    if (not(b <= a)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(b <= a)" << "\n";
    }
    if (not(b >= a)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(b >= a)" << "\n";
    }
    if (not(b == c)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(b == c)" << "\n";
    }
    if (not(b >= c)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(b >= c)" << "\n";
    }
    if (not(b <= c)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(b <= c)" << "\n";
    }
    if (not(a == c)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(a == c)" << "\n";
    }
    if (not(a >= c)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(a >= c)" << "\n";
    }
    if (not(a <= c)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(a <= c)" << "\n";
    }

    rational d { 109, 10 };
    if (not(d < a)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(d < a)" << "\n";
    }
    if (not(d <= a)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(d <= a)" << "\n";
    }
    if (not(d != a)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(d != a)" << "\n";
    }
    if (not(a > d)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(a > d)" << "\n";
    }
    if (not(a >= d)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(a >= d)" << "\n";
    }
    if (not(a != d)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(a != d)" << "\n";
    }

    rational e { 241, 20 };
    if (not(e > a)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(e > a)" << "\n";
    }
    if (not(e >= a)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(e >= a)" << "\n";
    }
    if (not(e != a)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(e != a)" << "\n";
    }
    if (not(a < e)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(a < e)" << "\n";
    }
    if (not(a <= e)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(a <= e)" << "\n";
    }
    if (not(a != e)) {
        std::cerr << "FAIL in " << __FILE_NAME__ << " in line " << __LINE__ << " " << "(a != e)" << "\n";
    }

    return 0;
}
