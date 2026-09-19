/** @file list4511.cpp */
/** Listing 45-11. Using replace_if and a Lambda to Replace All Integers in [10, 20] with 0 */
#include "data.hpp"
#include <algorithm>
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
    intvector data {};
    read_data(data);
    write_data(data);
    std::ranges::replace_if(data, [](int x) { return x >= 10 and x <= 20; }, 0);
    write_data(data);
    return 0;
}
