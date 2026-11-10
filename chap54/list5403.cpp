/** Listing 54-3. Specializing pair for One void Argument */
#include <iostream>

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

template<class U>
struct pair<void, U> {
    typedef void first_type;
    typedef U second_type;
    U second;
    pair() = default;
    pair(pair const &) = default;
    pair(U const &second): second { second } { }
    template<class U2>
    pair(pair<void, U2> const &other);
};

int
main()
{
    pair<void, int> p { 42 };
    std::cout << p.second << '\n';
}
