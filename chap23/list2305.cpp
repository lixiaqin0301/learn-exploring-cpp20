// Copied from list2205.cpp but is_palindrome() replaced by #include

#include <algorithm>
#include <fstream>
#include <iostream>
#include <locale>
#include <ranges>
#include <string>
#include <string_view>

/** Test for letter.
 * @param ch the character to test
 * @return true if @p ch is a letter
 */
bool
letter(char ch)
{
    return std::isalpha(ch, std::locale {});
}

/** Convert to lowercase.
 * @param ch the character to test
 * @return the character converted to lowercase
 */
char
lowercase(char ch)
{
    return std::tolower(ch, std::locale {});
}

#include "list2305.hh"

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

    std::locale::global(std::locale { "" });
    std::cin.imbue(std::locale {});
    std::cout.imbue(std::locale {});

    std::string line {};
    while (std::getline(std::cin, line))
        if (is_palindrome(line)) {
            std::cout << line << '\n';
        }
}
