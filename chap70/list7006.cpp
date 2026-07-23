#include <fstream>
#include <iostream>
#include <string>

#include "list7004.hh"
#include "list7006.hh"
#include "list7007.hh"
#include "list7008.hh"

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

    using string = mystring<char, array_storage<char, 256>>;
    string s;
    while (std::cin >> s) {
        std::cout << '"' << s << "\"\n";
    }
}
