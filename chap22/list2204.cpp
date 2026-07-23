/** @file list2204.cpp */
/** Listing 22-4. Sorting into Descending Order */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

/** Predicate for sorting into descending order. */
int
descending(int a, int b)
{
    return a > b;
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

    std::ranges::sort(data, descending);

    std::ranges::copy(data, std::ostream_iterator<int>(std::cout, "\n"));
}
