/** Listing 31-7. Arithmetic Operators for the rational Type */
#include "rational_class.hpp"
#include "test.hpp"

int
main()
{
    rational a { 1, 2 };
    rational b { 1, 3 };
    rational c { 1, 4 };
    rational d { 1, 6 };
    rational e { 1 };
    rational f { 2 };
    rational g { 3 };

    TEST(e - a == a);
    TEST(g - e == f);
    TEST(a * b == d);
    TEST(a * f == e);
    TEST(c * f == a);
    TEST(e / g == b);
    TEST(f / g == b + b);

    return 0;
}
