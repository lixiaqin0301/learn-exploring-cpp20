/** @file list1003.cpp */
/** Listing 10-3. Demonstrating the std::back_inserter Function */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
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
    std::ranges::copy(std::ranges::istream_view<int>(std::cin), std::back_inserter(data));
    std::ranges::sort(data);
    std::ranges::copy(data, std::ostream_iterator<int> { std::cout, "\n" });
}
