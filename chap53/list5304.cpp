/** Listing 53-4. The Primary std::less Class Template */
#include <iostream>

template<class T>
struct less {
    bool operator()(T const &a, T const &b) const { return a < b; }
};

int
main()
{
    less<int> const x;
    if (x(1, 2)) {
        std::cout << "success\n";
    } else {
        std::cout << "fail\n";
    }
}
