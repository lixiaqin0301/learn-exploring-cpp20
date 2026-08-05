/** Listing 23-5. Testing for Palindromes */

#include <fstream>
#include <iostream>
#include <locale>
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

/** Determine whether @p str is a palindrome.
 * Only letter characters are tested. Spaces and punctuation don't count.
 * @param str the string to test
 * @return true if @p str is the same forward and backward
 */
bool
is_palindrome(std::string_view str)
{
    if (str.empty()) {
        return true;
    }
    for (auto left { str.begin() }, right { str.end() - 1 }; left < right;) {
        if (not letter(*left)) {
            ++left;
        } else if (not letter(*right)) {
            --right;
        } else if (lowercase(*left) != lowercase(*right)) {
            return false;
        } else {
            ++left;
            --right;
        }
    }
    return true;
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

    std::locale::global(std::locale { "" });
    std::cin.imbue(std::locale {});
    std::cout.imbue(std::locale {});

    std::string line {};
    while (std::getline(std::cin, line)) {
        if (is_palindrome(line)) {
            std::cout << line << '\n';
        }
    }

    return 0;
}
