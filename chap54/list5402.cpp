/** Listing 54-2. Specializing pair<> for Two void Arguments */
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

template<>
struct pair<void, void> {
    using first_type = void;
    using second_type = void;
    pair(pair const &) = default;
    pair() = default;
    pair &operator=(pair const &) = default;
};

int
main()
{
    pair<void, void> a, b;
    a = b;
    std::cout << sizeof(a) << '\n';
}
