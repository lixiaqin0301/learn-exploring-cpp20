/** @file list5205.cpp */
/** Listing 52-5. Testing rational Comparison Operator */
#include <fstream>
#include <iostream>
#include <string>

#include "rational.hpp"

int
main(int argc, char *argv[])
{
    std::ifstream input;
    if (argc > 0 && argv[0] != nullptr) {
        input.open(std::string(argv[0]) + ".input");
        if (input.is_open()) {
            std::cin.rdbuf(input.rdbuf());
        }
    }

    static const rational<int> zero {};
    rational<int> r {};
    while (std::cin >> r)
        if (r != zero) {
            std::cout << r << '\n';
        }
}
