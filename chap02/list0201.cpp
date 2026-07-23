/** @file list0201.cpp */
/** Listing 2-1. Reading Test */
/// Read the program and determine what the program does.

#include <fstream>
#include <iostream>
#include <limits>
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

    int min { std::numeric_limits<int>::max() };
    int max { std::numeric_limits<int>::min() };
    bool any { false };
    int x = 0;
    while (std::cin >> x) {
        any = true;
        if (x < min) {
            min = x;
        }
        if (x > max) {
            max = x;
        }
    }

    if (any) {
        std::cout << "min = " << min << "\nmax = " << max << '\n';
    }

    return 0;
}
