/** @file list2002.cpp */
/** Listing 20-2. Separating Function Declarations from Definitions */
#include <fstream>
#include <iostream>
#include <string>

void ignore_line();
int prompted_read(std::string prompt);
void print_result(int count, int sum);

/** Main program.
 * Read integers from the standard input and print statistics about them.
 */
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
    int sum { 0 }, count { 0 };
    while (std::cin) {
        if (int x { prompted_read("Value: ") }; std::cin) {
            sum = sum + x;
            ++count;
        }
    }
    print_result(count, sum);
    return 0;
}

/** Prompt the user, then read a number, and ignore the rest of the line.
 * @param prompt the prompt string
 * @return the input number or -1 for end-of-file
 */
int
prompted_read(std::string prompt)
{
    std::cout << prompt;
    int x { -1 };
    std::cin >> x;
    ignore_line();
    return x;
}

/** Ignore the rest of the input line. */
void
ignore_line()
{
    char c {};
    while (std::cin.get(c) and c != '\n') {
        /*empty*/;
    }
    return;
}

/** Print the statistics.
 * @param count the number of values
 * @param sum the sum of the values
 */
void
print_result(int count, int sum)
{
    if (count == 0) {
        std::cout << "no data\n";
        return;
    }

    std::cout << "\ncount = " << count;
    std::cout << "\nsum   = " << sum;
    std::cout << "\nmean  = " << sum / count << '\n';

    return;
}
