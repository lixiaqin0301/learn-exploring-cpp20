/** @file list4601.cpp */
/** Listing 46-1. Comparing Iterators by Using the < Operator */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
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

    std::vector<int> data { std::istream_iterator<int>(std::cin), std::istream_iterator<int>() };

    for (auto start { data.begin() }, end { data.end() }; start < end; ++start) {
        --end; // now end points to a real position, possibly start
        std::iter_swap(start, end); // swap contents of two iterators
    }

    std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, "\n"));
}
