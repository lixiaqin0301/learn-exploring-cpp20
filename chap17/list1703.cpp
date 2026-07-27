/** @file list1703.cpp */
/** Listing 17-3. Reading and Writing Points */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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

    using intvec = std::vector<int>;
    intvec xs {}, ys {}; // store the x's and y's

    char sep {};
    // Loop while the input stream has an integer (x), a character (sep), and another integer (y); then test that the separator is a comma.
    for (int x {}, y {}; std::cin >> x >> sep and sep == ',' and std::cin >> y;) {
        xs.emplace_back(x);
        ys.emplace_back(y);
    }

    for (auto x { xs.begin() }, y { ys.begin() }; x != xs.end(); ++x, ++y) {
        std::cout << *x << ',' << *y << '\n';
    }

    return 0;
}
