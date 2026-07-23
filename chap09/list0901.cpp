/** @file list0901.cpp */
/** Listing 9-1. Sorting Integers */
#include <algorithm>
#include <fstream>
#include <iostream>
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

    std::vector<int> data {}; // initialized to be empty
    int x {};

    // Read integers one at a time.
    while (std::cin >> x)
        // Store each integer in the vector.
        data.emplace_back(x);

    // Sort the vector.
    std::ranges::sort(data);

    // Print the vector, one number per line.
    for (int element : data) {
        std::cout << element << '\n';
    }
}
