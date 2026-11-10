/** Listing 54-4. Specializing pair for the Other void Argument */
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

template<class T>
struct pair<T, void> {
    typedef T first_type;
    typedef void second_type;
    T first;
    pair() = default;
    pair(pair const &) = default;
    pair(T const &first): first { first } { }
    template<class T2>
    pair(pair<T2, void> const &other);
};

int
main()
{
    pair<int, void> p { 42 };
    std::cout << p.first << '\n';
}
