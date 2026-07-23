/** @file list5108.cpp */
/** Listing 51-8. Multiple Template Arguments */
#include <fstream>
#include <iostream>
#include <string>

template <class T, class U>
U
input_sum(std::istream &in)
{
    T x {};
    U sum { 0 };
    while (in >> x) {
        sum += x;
    }
    return sum;
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

    long sum { input_sum<int, long>(std::cin) };
    std::cout << sum << '\n';
}
