/** Listing 51-10. Another Way to Implement the copy Algorithm */
#include <iostream>
#include <iterator>
#include <vector>

auto
copy(auto range, auto output)
{
    for (auto const &item : range) {
        *output++ = item;
    }
    return output;
}

int
main()
{
    std::vector<int> inp { 1, 2, 3, 4 };
    std::vector<int> out {};
    copy(inp, std::back_inserter(out));
    for (auto x : out) {
        std::cout << x << '\n';
    }
}
