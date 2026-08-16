/** Listing 32-2. Output Operator */
#include "rational_class.hpp"
#include <fstream>

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
    rational r { 0 };
    std::cin >> r;
    std::cout << "r = " << r << '\n';
    return 0;
}
