/** @file list0302.cpp */
/** Listing 3-2. Print Average, Testing for a Zero Count */
/// Read integers and print their average.
/// Print nothing if the input is empty.

#include <fstream>
#include <iostream>
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

    int sum { 0 };
    int count {};

    int x = 0;
    while (std::cin >> x) {
        sum = sum + x;
        count = count + 1;
    }

    if (count != 0) {
        std::cout << "average = " << sum / count << '\n';
    }

    return 0;
}
