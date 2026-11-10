/** Listing 54-1. The pair Class Template */
#include <iostream>
#include <string>

template<class T, class U>
struct pair {
    using first_type = T;
    using second_type = U;
    T first;
    U second;
    pair();
    pair(T const &first, U const &second);
    template<class T2, class U2>
    pair(pair<T2, U2> const &other);
};

template<class T, class U>
pair<T, U>::pair(T const &first, U const &second): first(first), second(second)
{
}

int
main()
{
    pair<int, std::string> p { 1, "test" };
    std::cout << p.first << ' ' << p.second << '\n';
}
