/** @file list2701.cpp */
/** Listing 27-1. Floating-Point Numbers Do Not Always Behave As You Expect */
#include <iostream>
int
main()
{
    float a { 0.03F };
    float b { 10.0F };
    float c { 0.3F };
    if (a * b == c) {
        std::cout << "a * b == c\n";
    } else {
        std::cout << "a * b != c\n";
    }
    return 0;
}
