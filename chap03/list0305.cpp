/** @file list0305.cpp */
/** Listing 3-5. Print Average, Testing for a Zero Count */
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

    int x;
    while (std::cin >> x) {
        sum = sum + x;
        count = count + 1;
    }

    if (count == 0) {
        std::cout << "No data.\n";
    } else {
        std::cout << "average = " << sum / count << '\n';
    }
}
