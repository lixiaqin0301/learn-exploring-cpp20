/** @file list4405.cpp */
/** Listing 44-5. Another Program for Generating Successive Integers */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "sequence.hpp"

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

    int size {};
    std::cout << "How many integers do you want? ";
    std::cin >> size;
    int first {};
    std::cout << "What is the first integer? ";
    std::cin >> first;
    int step {};
    std::cout << "What is the interval between successive integers? ";
    std::cin >> step;

    std::vector<int> data(size);
    // Generate the integers to fill the vector.
    std::ranges::generate(data, sequence(first, step));

    // Print the resulting integers, one per line.
    std::ranges::copy(data, std::ostream_iterator<int>(std::cout, "\n"));
}
