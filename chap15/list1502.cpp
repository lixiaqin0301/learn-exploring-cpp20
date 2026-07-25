/** @file list1502.cpp */
/** Listing 15-2. Printing Word Frequencies */
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

    // Read words from the standard input and count the number of times each word occurs.
    std::string word {};
    while (std::cin >> word) {
        ++counts[word];
    }

    // For each word/count pair...
    for (auto element : counts) {
        // Print the word, tab, the count, newline.
        std::cout << element.first << '\t' << element.second << '\n';
    }

    return 0;
}
