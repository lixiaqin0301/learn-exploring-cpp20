/** @file list4702.cpp */
/** Listing 47-2. Demonstrating Range Functions */
#include <fstream>
#include <iostream>
#include <ranges>
#include <string>

int
main(int argc, char *argv[])
{
    std::ifstream input_stream;
    if (argc > 0 && argv[0] != nullptr) {
        input_stream.open(std::string(argv[0]) + ".input");
        if (input_stream.is_open()) {
            std::cin.rdbuf(input_stream.rdbuf());
        }
    }

    std::cout << "Enter an integer: ";
    int input {};
    if (std::cin >> input) {
        for (auto x : std::ranges::single_view { input }) {
            std::cout << x << '\n';
        }
    }
}
