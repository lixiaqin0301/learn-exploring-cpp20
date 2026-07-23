/** @file list6804.cpp */
/** Listing 68-4. Demonstrating the enum_map Type */
#include <fstream>
#include <iostream>
#include <string>

#include "enums.hpp"

enum class language { apl, low = apl, cpp, haskell, lisp, scala, high = scala };

enum_map<language> const languages { { "apl", language::apl }, { "c++", language::cpp }, { "haskell", language::haskell }, { "lisp", language::lisp }, { "scala", language::scala } };

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

    language lang;
    while (std::cin) {
        try {
            if (read(std::cin, languages, lang)) {
                write(std::cout, languages, lang);
                std::cout << '\n';
            }
        } catch (std::out_of_range const &ex) {
            std::cout << ex.what() << '\n';
        }
    }
}
