#include "stats.hpp"
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

    std::cout << "Bogus Metabolic Indicator\n";
    vital_stats stats;
    int count { 0 };
    while (stats.read(std::cin, count)) {
        static constexpr int threshold { 30 };
        ++count;
        stats.print(std::cout, threshold);
    }
}
