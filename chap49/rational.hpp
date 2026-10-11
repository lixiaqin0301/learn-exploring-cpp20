#ifndef RATIONAL_HPP_
#define RATIONAL_HPP_

#include <iostream>
#include <numeric>
#include <stdexcept>

class rational {
public:
    class zero_denominator : public std::logic_error {
    public:
        using std::logic_error::logic_error;
    };
    rational() noexcept: rational { 0 } { }
    explicit rational(int num) noexcept: numerator_ { num }, denominator_ { 1 } { }
    rational(int num, int den): numerator_ { den < 0 ? -num : num }, denominator_ { den == 0 ? throw zero_denominator("0 denominator") : (den < 0 ? -den : den) } { reduce(); }
    rational(double r): rational { static_cast<int>(r * 100000), 100000 } { }

    int numerator() const noexcept { return numerator_; }
    int denominator() const noexcept { return denominator_; }
    float as_float() const;
    double as_double() const;
    long double as_long_double() const;

    rational const &operator=(int) noexcept;
    rational const &operator+=(rational const &rhs)
    {
        numerator_ = numerator() * rhs.denominator() + rhs.numerator() * denominator();
        denominator_ *= rhs.denominator();
        reduce();
        return *this;
    }
    rational const &operator-=(rational const &rhs)
    {
        numerator_ = numerator() * rhs.denominator() - rhs.numerator() * denominator();
        denominator_ *= rhs.denominator();
        reduce();
        return *this;
    }
    rational const &operator*=(rational const &rhs)
    {
        numerator_ *= rhs.numerator();
        denominator_ *= rhs.denominator();
        reduce();
        return *this;
    }
    rational const &operator/=(rational const &rhs)
    {
        if (rhs.numerator() == 0)
            throw zero_denominator { "divide by zero" };
        numerator_ *= rhs.denominator();
        denominator_ *= rhs.numerator();
        if (denominator_ < 0) {
            denominator_ = -denominator_;
            numerator_ = -numerator_;
        }
        reduce();
        return *this;
    }
    rational const &operator++()
    {
        numerator_ += denominator_;
        return *this;
    }
    rational const &operator--();
    rational operator++(int)
    {
        rational result { *this };
        numerator_ += denominator_;
        return result;
    }
    rational operator--(int)
    {
        rational result { *this };
        numerator_ -= denominator_;
        return result;
    }
private:
    void reduce();
    void normalize();
    int init_denominator(int den)
    {
        if (den == 0) {
            throw zero_denominator("0 denominator");
        } else if (den < 0) {
            return -den;
        } else {
            return den;
        }
    }
    int numerator_;
    int denominator_;
};

rational abs(rational const &r);
rational operator-(rational const &r);
rational operator+(rational const &lhs, rational const &rhs);
rational operator-(rational const &lhs, rational const &rhs);
inline rational
operator*(rational const &lhs, rational const &rhs)
{
    rational result { lhs };
    result *= rhs;
    return result;
}
rational operator/(rational const &lhs, rational const &rhs);

bool operator==(rational const &a, rational const &b);
bool operator<(rational const &a, rational const &b);

inline bool
operator!=(rational const &a, rational const &b)
{
    return not(a == b);
}

inline bool
operator<=(rational const &a, rational const &b)
{
    return not(b < a);
}

inline bool
operator>(rational const &a, rational const &b)
{
    return b < a;
}

inline bool
operator>=(rational const &a, rational const &b)
{
    return not(b > a);
}

std::istream &operator>>(std::istream &in, rational &rat);
std::ostream &operator<<(std::ostream &out, rational const &rat);

inline void
rational::reduce()
{
    if (denominator_ == 0) {
        throw zero_denominator { "denominator is zero" };
    }
    if (denominator_ < 0) {
        denominator_ = -denominator_;
        numerator_ = -numerator_;
    }
    int div { std::gcd(numerator_, denominator_) };
    numerator_ = numerator_ / div;
    denominator_ = denominator_ / div;
}

inline std::ostream &
operator<<(std::ostream &stream, rational const &r)
{
    std::cout << r.numerator() << '/' << r.denominator();
    return stream;
}

inline bool
operator==(rational const &lhs, rational const &rhs)
{
    return lhs.numerator() == rhs.numerator() and lhs.denominator() == rhs.denominator();
}

inline bool
operator<(rational const &lhs, rational const &rhs)
{
    if (lhs.denominator() == rhs.denominator()) {
        return lhs.numerator() < rhs.numerator();
    } else {
        return lhs.numerator() * rhs.denominator() < lhs.denominator() * rhs.numerator();
    }
}

inline rational
operator-(rational const &r)
{
    return rational { -r.numerator(), r.denominator() };
}

#endif
