/** @file list2301.cpp */
/** Listing 23-1. Calling transform to Apply a Function to Each Element of an Array */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

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

    std::vector<int> data { std::istream_iterator<int>(std::cin), std::istream_iterator<int>() };

    std::transform(data.begin(), data.end(), data.begin(), times_two);
    std::transform(data.begin(), data.end(), data.begin(), plus_three);

    std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, "\n"));
}
