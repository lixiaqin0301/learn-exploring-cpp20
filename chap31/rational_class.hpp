#ifndef RATIONAL_CLASS_HPP_
#define RATIONAL_CLASS_HPP_

#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>

/// Represents a rational number.
struct rational { /// Constructs a rational object, given a numerator and a denominator.
    /// Always reduces to normal form.
    /// @param num numerator
    /// @param den denominator
    /// @pre denominator > 0
    rational(int num, int den): numerator { num }, denominator { den } { reduce(); }

    rational(int num): numerator { num }, denominator { 1 } { }

    /// Assigns a numerator and a denominator, then reduces to normal form.
    /// @param num numerator
    /// @param den denominator
    /// @pre denominator > 0
    void assign(int num, int den)
    {
        numerator = num;
        denominator = den;
        reduce();
    }

    /// Reduces the numerator and denominator by their GCD.
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

    int numerator; ///< numerator gets the sign of the rational value
    int denominator; ///< denominator is always positive
};

/// Compares two rational numbers for equality.
/// @pre @p a and @p b are reduced to normal form
inline bool
operator==(rational const &a, rational const &b)
{
    return a.numerator == b.numerator and a.denominator == b.denominator;
}

/// Compares two rational numbers for inequality.
/// @pre @p a and @p b are reduced to normal form
inline bool
operator!=(rational const &a, rational const &b)
{
    return not(a == b);
}

/// Compares two rational numbers for less-than.
inline bool
operator<(rational const &a, rational const &b)
{
    return a.numerator * b.denominator < b.numerator * a.denominator;
}

/// Compares two rational numbers for less-than-or-equal.
inline bool
operator<=(rational const &a, rational const &b)
{
    return not(b < a);
}

/// Compares two rational numbers for greater-than.
inline bool
operator>(rational const &a, rational const &b)
{
    return b < a;
}

/// Compares two rational numbers for greater-than-or-equal.
inline bool
operator>=(rational const &a, rational const &b)
{
    return not(b > a);
}

inline rational
operator+(rational const &lhs, rational const &rhs)
{
    return rational { lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator, lhs.denominator * rhs.denominator };
}

inline rational
operator-(rational const &r)
{
    return rational { -r.numerator, r.denominator };
}

inline rational
operator-(rational const &lhs, rational const &rhs)
{
    return rational { lhs.numerator * rhs.denominator - rhs.numerator * lhs.denominator, lhs.denominator * rhs.denominator };
}

inline rational
operator*(rational const &lhs, rational const &rhs)
{
    return rational { lhs.numerator * rhs.numerator, lhs.denominator * rhs.denominator };
}

inline rational
operator/(rational const &lhs, rational const &rhs)
{
    return rational { lhs.numerator * rhs.denominator, lhs.denominator * rhs.numerator };
}

inline rational
operator*(rational const &rat, int mult)
{
    return rational { rat.numerator * mult, rat.denominator };
}

inline rational
operator*(int mult, rational const &rat)
{
    return rat * mult;
}

inline rational
absval(rational const &r)
{
    return rational { std::abs(r.numerator), r.denominator };
}

#endif
