/** @file list6402.cpp */
/** Listing 64-2. Moving Strings Instead of Copying Them */
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class mystring : public std::string {
public:
    mystring()
        : std::string {}
    {
        std::cout << "mystring()\n";
    }
    mystring(mystring const &copy)
        : std::string { copy }
    {
        std::cout << "mystring copy(\"" << *this << "\")\n";
    }
    mystring(mystring &&move) noexcept
        : std::string { std::move(move) }
    {
        std::cout << "mystring move(\"" << *this << "\")\n";
    }
};

std::vector<mystring>
read_data()
{
    std::vector<mystring> strings {};
    mystring line {};
    while (std::getline(std::cin, line)) {
        strings.emplace_back(std::move(line));
    }
    return strings;
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

    std::vector<mystring> strings;
    strings = read_data();
}
