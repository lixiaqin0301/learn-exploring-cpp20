/** @file list7003.cpp */
/** Listing 70-3. Using Character Traits When Copying Input to Output */
#include <fstream>
#include <iostream>
#include <string>
#include <string> // for char_traits

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

    using char_traits = std::char_traits<char>; // for brevity and clarity
    char_traits::int_type c {};
    while (c = std::cin.get(), not char_traits::eq_int_type(c, char_traits::eof())) {
        std::cout.put(char_traits::to_char_type(c));
    }
}
