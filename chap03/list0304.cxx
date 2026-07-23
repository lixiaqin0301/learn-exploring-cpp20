/** @file list0304.cxx */
/** Listing 3-4. Testing for Even or Odd Integers */
/// Read integers and print a message that tells the user
/// whether the number is even or odd.

#include <fstream>
#include <iostream>

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
    int x = 0;
    while (std::cin >> x) {
        if (x % 2 == 0) { // Fill in the condition.
            std::cout << x << " is even.\n";
        } else {
            std::cout << x << " is odd.\n";
        }
    }
    return 0;
}
