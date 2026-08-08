/** @file list2401.cpp */
/** Listing 24-1. Calling transform to Apply a Lambda to Each Element of an Array */
#include <fstream>
#include <iostream>
#include <ranges>
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
    auto data { std::ranges::istream_view<int>(std::cin)
        | std::views::transform([](int i) { return i * 2; })
        | std::views::transform([](int i) { return i + 3; })
    };
    for (auto element : data) {
        std::cout << element << '\n';
    }
    return 0;
}
