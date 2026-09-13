/** @file list4504.cpp */
/** Listing 45-4. Using find_if and intrange to Find an Integer That Lies Within a Range */
#include "data.hpp"
#include "intrange.hpp"
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
    if (auto iter { std::ranges::find_if(data, intrange { 10, 20 }) }; iter == data.end()) {
        std::cout << "No values in [10,20] found\n";
    } else {
        std::cout << "Value " << *iter << " in range [10,20].\n";
    }
    return 0;
}
