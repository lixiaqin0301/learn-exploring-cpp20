/** @file list0502.cpp */
/** Listing 5-2. Reading Strings */
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

    std::cout << "What is your name? ";
    std::string name {};
    std::cin >> name;
    std::cout << "Hello, " << name << ", how are you? ";
    std::string response {};
    std::cin >> response;
    std::cout << "Good-bye, " << name << ". I'm glad you feel " << response << "\n";
}
