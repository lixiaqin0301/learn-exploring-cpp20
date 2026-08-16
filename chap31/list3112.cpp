/** @file list3112.cpp */
/** Listing 31-12. Converting to Floating-Point Types */
#include <cassert>
#include <iostream>
#include <numeric>

struct rational {
    float as_float() { return static_cast<float>(numerator) / denominator; }

    double as_double() { return numerator / static_cast<double>(denominator); }

    long double as_long_double() { return static_cast<long double>(numerator) / static_cast<long double>(denominator); }

    // ... omitted for brevity ...
    /// Constructs a rational object, given a numerator and a denominator.
    /// Always reduces to normal form.
    /// @param num numerator
    /// @param den denominator
    /// @pre denominator > 0
    rational(int num, int den): numerator { num }, denominator { den } { reduce(); }

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

int
main()
{
    rational pi { 355, 113 };
    rational bmi { 90 * 100 * 100, 180 * 180 }; // Bogus-metabolic indicator of 90kg, 180cm
    double circumference { 0 }, radius { 10 };

    circumference = 2 * pi.as_double() * radius;
    std::cout << "circumference of circle with radius " << radius << " is about " << circumference << '\n';
    std::cout << "bmi = " << bmi.as_float() << '\n';
    return 0;
}
