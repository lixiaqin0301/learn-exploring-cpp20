/** Listing 33-2. Assignment Operator with Explicit Use of this-> */

#include <cassert>
#include <numeric>

class rational {
public:
    rational &operator=(rational const &that)
    {
        this->numerator = that.numerator;
        this->denominator = that.denominator;
        reduce();
        return *this;
    }
    int numerator;
    int denominator;
    void reduce()
    {
        assert(denominator != 0);
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
        int div { std::gcd(numerator, denominator) };
        numerator = numerator / div;
        denominator = denominator / div;
    }
};

int
main()
{
    rational a;
    a.numerator = 1;
    a.denominator = 1;
    rational b;
    b = a;
    return 0;
}
