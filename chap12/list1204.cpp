/** @file list1204.cpp */
/** Listing 12-4. Using Short-Circuiting to Test for Nonzero Vector Elements */
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

    std::vector<int> data {};
    std::ranges::copy(std::ranges::istream_view<int>(std::cin), std::back_inserter(data));

    auto iter { data.begin() }, end { data.end() };
    for (; iter != end and *iter == 0; ++iter) {
        /*empty*/;
    }
    if (iter == end) {
        std::cout << "data contains all zeroes\n";
    } else {
        std::cout << "data does not contain all zeroes\n";
    }

    return 0;
}
