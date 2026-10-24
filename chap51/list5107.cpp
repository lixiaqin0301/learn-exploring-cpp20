/** Listing 51-7. The std::min Algorithm */
#include <iostream>

template <class T>
T
min(T a, T b)
{
    if (b < a) {
        return b;
    } else {
        return a;
    }
}

int
main()
{
    int x { 10 }, y { 20 }, z { min(x, y) };
    std::cout << z << '\n';
}
