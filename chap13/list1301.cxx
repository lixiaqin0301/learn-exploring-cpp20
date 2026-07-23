/** @file list1301.cxx */
/** Listing 13-1. Finding Statement Errors */
#include <fstream>
#include <iostream>
#include <vector>
// find errors in this program
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
    std::vector<int> positive_data {}, negative_data {};

    for (int x { 0 }; std::cin >> x;) {
        if (x < 0) {
            negative_data.push_back(x);
        } else {
            positive_data.push_back(x);
        }
    };

    return 0;
}
