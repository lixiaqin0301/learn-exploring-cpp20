/** @file list0504.cpp */
/** Listing 5-4. Getting the User’s Age and Then Name */
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

    std::cout << "How old are you? ";
    int age {};
    std::cin >> age;

    std::cout << "What is your name? ";
    std::string name {};
    std::cin >> name;

    std::cout << "Good-bye, " << name << ". You are " << age << " year";
    if (age != 1) {
        std::cout << 's';
    }
    std::cout << " old.\n";
}
