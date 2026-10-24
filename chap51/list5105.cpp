/** Listing 51-5. One Way to Implement the copy Algorithm */
#include <iostream>
#include <iterator>
#include <vector>

template <class InputRange, class OutputIterator>
OutputIterator
copy(InputRange range, OutputIterator output)
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
