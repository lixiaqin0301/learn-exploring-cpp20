/** @file list4501.cpp */
/** Listing 45-1. Searching for an Integer */
#include "data.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>

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
    read_data(data);
    write_data(data);
    if (auto iter { std::ranges::find(data, 42) }; iter == data.end()) {
        std::cout << "Value 42 not found\n";
    } else {
        *iter = 0;
        std::cout << "Value 42 changed to 0:\n";
        write_data(data);
    }
    return 0;
}
