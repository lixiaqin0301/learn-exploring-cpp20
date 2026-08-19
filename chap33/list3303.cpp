/** Listing 33-3. Assignment of an Integer to a rational */
#include <cassert>
#include <numeric>

class rational {
public:
    rational() = default;
    rational(rational const &rhs) = default;
    rational(rational &&rhs) noexcept = default;
    rational &operator=(rational const &rhs) = default;
    rational &operator=(rational &&rhs) noexcept = default;
    ~rational() = default;
    explicit rational(int num)
    {
        numerator = num;
        denominator = 1;
    }
    rational &operator=(int num)
    {
        this->numerator = num;
        this->denominator = 1; // no need to call reduce()
        return *this;
    }

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
    rational r;
    r = 2;
    return 0;
}
