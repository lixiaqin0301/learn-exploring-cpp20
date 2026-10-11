#include "rational.hpp"

int
main()
{
    std::cout << std::boolalpha << (rational { 1, 2 } == rational { 4, 8 }) << '\n';
    return 0;
}
