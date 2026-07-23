/** @file list1002.cpp */
/** Listing 10-2. Demonstrating the std::ostream_iterator Class */
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

    std::vector<int> data;
    int element;
    while (std::cin >> element) {
        data.emplace_back(element);
    }

    std::ranges::sort(data);

    std::ranges::copy(data, std::ostream_iterator<int> { std::cout, "\n" });

    return 0;
}
