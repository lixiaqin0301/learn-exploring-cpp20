/** @file list1501.cpp */
/** Listing 15-1. Counting Occurrences of Unique Words */
#include <fstream>
#include <iostream>
#include <map>
#include <string>

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

    std::map<std::string, int> counts {};
    std::string word {};
    while (std::cin >> word) {
        ++counts[word];
    }
    // TODO: Print the results.
}
