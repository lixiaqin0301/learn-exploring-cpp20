/** Listing 34-4. Member Functions for Class point */
#include <cmath> // for sqrt and atan2
#include <iostream>

struct point {
    /// Distance to the origin.
    double distance() { return std::sqrt(x * x + y * y); }
    /// Angle relative to x-axis.
    double angle() { return std::atan2(y, x); }

    /// Add an offset to x and y.
    void offset(double off) { offset(off, off); }
    /// Add an offset to x and an offset to y
    void offset(double xoff, double yoff)
    {
        x = x + xoff;
        y = y + yoff;
    }

    /// Scale x and y.
    void scale(double mult) { this->scale(mult, mult); }
    /// Scale x and y.
    void scale(double xmult, double ymult)
    {
        this->x = this->x * xmult;
        this->y = this->y * ymult;
    }
    double x;
    double y;
};

int
main()
{
    point a;
    a.x = 1.0;
    a.y = 1.0;
    a.scale(2.5);
    std::cout << a.x << ',' << a.y << '\n';
    a.scale(2.0, 3.0);
    std::cout << a.x << ',' << a.y << '\n';
    a.offset(-1.0);
    std::cout << a.x << ',' << a.y << '\n';
    a.offset(2.0, 3.0);
    std::cout << a.x << ',' << a.y << '\n';
    std::cout << a.angle() << '\n';
    std::cout << a.distance() << '\n';
    return 0;
}
