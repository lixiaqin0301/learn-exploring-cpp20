#include "list5109.hh"
#include <iostream>
#include <ranges>
int
main()
{
    std::cout << std::boolalpha;
    for (int i : std::ranges::views::iota(0, 10)) {
        std::cout << i << ' ' << isprime(i) << '\n';
    }
}
