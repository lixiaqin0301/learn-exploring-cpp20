/** @file list4605.cpp */
/** Listing 46-5. Really Printing the Middle Item of a Series of Integers */
#include "data.hpp"
#include <fstream>
#include <iostream>
#include <iterator>

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
    intvector::const_iterator iter { data.begin() };
    std::advance(iter, data.size() / 2); // move to middle of vector
    if (not data.empty()) {
        std::cout << "middle item = " << *iter << '\n';
    }
    return 0;
}
