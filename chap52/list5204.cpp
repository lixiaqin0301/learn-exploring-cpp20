/** @file list5204.cpp */
/** Listing 52-4. Simple I/O Test of the rational Class Template */
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

    rational<int> r {};
    while (std::cin >> r) {
        std::cout << r << '\n';
    }
}
