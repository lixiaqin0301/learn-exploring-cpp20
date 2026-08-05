/** Listing 23-2. Sanitizing a String by Transforming and Filtering It */

#include <algorithm>
#include <format>
#include <fstream>
#include <iostream>
#include <locale>
#include <map>
#include <string>

/** Test whether to keep a letter.
 * @param ch the character to test
 * @return true to keep @p ch because it may be a character that makes up a word
 */
bool
keep(char ch)
{
    return std::isalnum(ch, std::locale {});
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

/** Sanitize a string by keeping only alphabetic characters.
 * @param str the original string
 * @return a sanitized copy of the string
 */
std::string
sanitize(std::string_view str)
{
    std::string result {};
    std::copy_if(str.begin(), str.end(), std::back_inserter(result), keep);
    std::transform(result.begin(), result.end(), result.begin(), lowercase);
    return result;
}

using count_map = std::map<std::string, int>; ///< Map words to counts
using count_pair = count_map::value_type; ///< pair of a word and a count
using str_size = std::string::size_type; ///< String size type

/** Initialize the I/O streams by imbuing them with the global locale.
 * Use this function to imbue the streams with the native locale.
 * C++ initially imbues streams with the classic locale.
 */
void
initialize_streams()
{
    std::cin.imbue(std::locale {});
    std::cout.imbue(std::locale {});
    return;
}

/** Find the longest key in a map.
 * @param map the map to search
 * @returns the size of the longest key in @p map
 */
str_size
get_longest_key(count_map const &map)
{
    str_size result { 0 };
    for (auto pair : map) {
        if (pair.first.size() > result) {
            result = pair.first.size();
        }
    }
    return result;
}

/** Print the word, count, newline. Keep the columns neatly aligned.
 * Rather than the tedious operation of measuring the magnitude of all the counts and then determining the necessary number of columns,
 * just use a sufficiently large value for the counts column.
 * @param pair a word/count pair
 * @param longest the size of the longest key; pad all keys to this size
 */
void
print_pair(count_pair const &pair, str_size longest)
{
    int constexpr count_size { 10 }; // Number of places for printing the count
    std::cout << std::format("{1:{0}}{3:{2}}\n", longest, pair.first, count_size, pair.second);
    return;
}

/** Print the results in neat columns.
 * @param counts the map of all the counts
 */
void
print_counts(count_map const &counts)
{
    str_size longest { get_longest_key(counts) };

    // For each word/count pair...
    for (count_pair pair : counts) {
        print_pair(pair, longest);
    }

    return;
}

/** Main program to count unique words in the standard input. */
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

    // Set the global locale to the native locale.
    std::locale::global(std::locale { "" });
    initialize_streams();

    count_map counts {};

    // Read words from the standard input and count the number of times each word occurs.
    std::string word {};
    while (std::cin >> word) {
        std::string copy { sanitize(word) };

        // The "word" might be all punctuation, so the copy would be empty.
        // Don't count empty strings.
        if (not copy.empty()) {
            ++counts[copy];
        }
    }

    print_counts(counts);

    return 0;
}
