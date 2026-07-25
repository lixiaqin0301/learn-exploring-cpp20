/** @file list1504.cpp */
/** Listing 15-4. Searching for a Word in a Map */
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

    auto the { counts.find("the") };
    if (the == counts.end()) {
        std::cout << "\"the\": not found\n";
    } else if (the->second == 1) {
        std::cout << "\"the\": occurs " << the->second << " time\n";
    } else {
        std::cout << "\"the\": occurs " << the->second << " times\n";
    }

    return 0;
}
