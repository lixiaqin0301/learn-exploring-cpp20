/** @file list2402.cpp */
/** Listing 24-2. Using a Lambda to Access Local Variables */
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

    std::cout << "Multiplier: ";
    int multiplier {};
    std::cin >> multiplier;

    auto data { std::ranges::istream_view<int>(std::cin) | std::views::transform([multiplier](int i) { return i * multiplier; }) };

    std::cout << "Data:\n";
    std::ranges::copy(data, std::ostream_iterator<int>(std::cout, "\n"));
}
