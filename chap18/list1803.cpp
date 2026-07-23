/** @file list1803.cpp */
/** Listing 18-3. Using the Native Locale for Output */
#include <fstream>
#include <iostream>
#include <locale>
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

    std::cout.imbue(std::locale { "" });

    int sum { 0 };
    int x {};
    while (std::cin >> x) {
        sum = sum + x;
    }
    std::cout << "sum = " << sum << '\n';
}
