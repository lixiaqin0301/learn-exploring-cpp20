/** @file list4001.cpp */
/** Listing 40-1. Computing BMI */
#include <fstream>
#include <iostream>
#include <string>

using height = int;
using weight = int;
using bmi = int;

bmi
compute_bmi(height h, weight w)
{
    return w * 10000 / (h * h);
}

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

    std::cout << "Height in centimeters: ";
    height h {};
    std::cin >> h;

    std::cout << "Weight in kilograms: ";
    weight w {};
    std::cin >> w;

    std::cout << "Bogus Metabolic Index = " << compute_bmi(w, h) << '\n';
}
