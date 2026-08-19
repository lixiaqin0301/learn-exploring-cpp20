/** Listing 33-4. Overloaded Constructors for rational */
#include <cassert>
#include <numeric>

class rational {
public:
    rational(): rational { 0, 1 } { }
    rational(rational const &rhs) = default;
    rational(rational &&rhs) noexcept = default;
    rational &operator=(rational const &rhs) = default;
    rational &operator=(rational &&rhs) noexcept = default;
    ~rational() = default;
    rational(int num, int den): numerator { num }, denominator { den } { reduce(); }

private:
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
    int numerator = 0;
    int denominator = 1;
};
int
main()
{
    rational a;
    return 0;
}
