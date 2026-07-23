/** @file list2201.cpp */
/** Listing 22-1. Calling transform to Apply a Function to Each Element of a Range */
#include <fstream>
#include <iostream>
#include <iterator>
#include <ranges>
#include <string>

int
times_two(int i)
{
    return i * 2;
}

int
plus_three(int i)
{
    return i + 3;
}

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

    auto data { std::ranges::istream_view<int>(std::cin) | std::ranges::views::transform(times_two) | std::ranges::views::transform(plus_three) };
    for (auto element : data) {
        std::cout << element << '\n';
    }
}
