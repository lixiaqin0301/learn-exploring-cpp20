/** @file list4211.cpp */
/** Listing 42-11. Main Program Imports a, b, and c */
// module;
#include "b.hpp"
#include "c.hpp"
#include <fstream>
#include <iostream>
#include <string>

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

    while (std::cin) {
        std::cout << "pi=" << pi << '\n';
        std::cout << "Radius=";
        double radius {};
        if (std::cin >> radius) {
            std::cout << "Area = " << area(radius) << '\n';
            std::cout << "Circumference = " << circumference(radius) << '\n';
        }
    }
}
