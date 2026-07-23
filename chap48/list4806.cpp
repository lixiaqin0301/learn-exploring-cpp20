/** @file list4806.cpp */
/** Listing 48-6. Using an I/O Stream Exception Mask */
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

    std::cin.exceptions(std::ios_base::badbit);
    std::cout.exceptions(std::ios_base::badbit);

    int x {};
    try {
        while (std::cin >> x) {
            std::cout << x << '\n';
        }
        if (not std::cin.eof()) {
            std::cerr << "Invalid integer input. Program terminated.\n";
        }
    } catch (std::ios_base::failure const &ex) {
        std::cerr << "Major I/O failure! Program terminated.\n" << ex.what() << '\n';
        std::terminate();
    }
}
