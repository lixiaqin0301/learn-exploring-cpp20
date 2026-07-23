/** @file list0301.cpp */
/** Listing 3-1. Integer Arithmetic */
/// Read the program and determine what the program does.

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

    int sum { 0 };
    int count {};

    int x;
    while (std::cin >> x) {
        sum = sum + x;
        count = count + 1;
    }

    std::cout << "average = " << sum / count << '\n';
}
