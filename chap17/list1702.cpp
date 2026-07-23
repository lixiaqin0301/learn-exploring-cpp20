/** @file list1702.cpp */
/** Listing 17-2. Echoing Input to Output, One Character at a Time */
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

    std::cin >> std::noskipws;
    char ch {};
    while (std::cin >> ch) {
        std::cout << ch;
    }
}
