/** Listing 51-6. Implementing the find Algorithm */
#include <iostream>
#include <vector>

template <class InputIterator, class T>
InputIterator
find(InputIterator start, InputIterator end, T value)
{
    for (; start != end; ++start) {
        if (*start == value) {
            return start;
        }
    }
    return end;
}

int
main()
{
    std::vector<int> data { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto i { ::find(data.begin(), data.end(), 5) };
    if (i == data.end()) {
        std::cout << "fail\n";
    } else if (*i == 5) {
        std::cout << "success\n";
    } else {
        std::cout << "fail at " << *i << '\n';
    }
}
