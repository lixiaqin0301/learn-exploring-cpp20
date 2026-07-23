/** @file list4509.cpp */
/** Listing 45-9. Testing Various Comparison Algorithms */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

#include "data.hpp"

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

    intvector data1 {};
    intvector data2 {};

    read_data(data1);

    std::cin.clear();
    std::string discard;
    std::cin >> discard;

    read_data(data2);

    std::cout << "data1: ";
    write_data(data1);
    std::cout << "data2: ";
    write_data(data2);

    std::cout << std::boolalpha;
    std::cout << "equal(data1, data2) = " << std::ranges::equal(data1, data2) << '\n';

    auto result { std::ranges::mismatch(data1, data2) };
    std::cout << "mismatch(data1, data2) = index " << std::distance(data1.begin(), result.in2) << '\n';

    std::cout << "lex_comp(data1, data2) = " << std::ranges::lexicographical_compare(data1, data2) << '\n';
}
