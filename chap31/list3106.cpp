/** Listing 31-6. Addition Operator for the rational Type */
#include "rational_class.hpp"
#include "test.hpp"

int
main()
{
    rational a { 1, 2 };
    rational b { 1 };
    rational c { -1, 2 };

    TEST(a + a == b);
    TEST(-a == c);
    TEST(a == -(-a));

    return 0;
}
