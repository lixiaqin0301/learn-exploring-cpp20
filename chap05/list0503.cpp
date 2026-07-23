/** @file list0503.cpp */
/** Listing 5-3. Getting the User’s Name and Age */
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

    std::cout << "Hello, " << name << ", how old are you? ";
    int age {};
    std::cin >> age;

    std::cout << "Good-bye, " << name << ". You are " << age << " year";
    if (age != 1) {
        std::cout << 's';
    }
    std::cout << " old.\n";
}
