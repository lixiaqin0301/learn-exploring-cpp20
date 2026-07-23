/** @file list4507.cpp */
/** Listing 45-7. Using lower_bound to Create a Sorted Vector */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <string>

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

    intvector data {};
    int value;
    while (std::cin >> value) {
        auto lb { std::lower_bound(data.begin(), data.end(), value) };
        auto ub { std::upper_bound(data.begin(), data.end(), value) };
        if (lb == ub)
            // Not in data, so insert.
            data.insert(ub, value);
        // else value is already in the vector
    }
    write_data(data);
}
