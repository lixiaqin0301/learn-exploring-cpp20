/** @file list4701.cpp */
/** Listing 47-1. Demonstrating Range Functions */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

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

    std::vector<int> data;
    std::cout << "Enter some numbers:\n";
    std::ranges::copy(std::ranges::istream_view<int>(std::cin), std::back_inserter(data));

    std::cout << "You entered " << std::ranges::size(data) << " values\n";
    if (not std::ranges::empty(data)) {
        std::ranges::sort(data);
        auto start { std::ranges::cbegin(data) };
        auto middle { start + std::ranges::size(data) / 2 };
        std::cout << "The median value is " << *middle << '\n';
    }
}
