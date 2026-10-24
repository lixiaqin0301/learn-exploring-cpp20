/** Listing 51-2. Writing a Function Template */
#include <iostream>

template <class T>
T
absval(T x)
{
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}

int
main()
{
    std::cout << absval(-1) << '\n';
    std::cout << absval(-1.5) << '\n';
}
