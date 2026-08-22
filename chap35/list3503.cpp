/** Listing 35-3. const Member Functions for Class point */
#include <cmath> // for sqrt and atan2
#include <iostream>

struct point {
    /// Distance to the origin.
    double distance() const { return std::sqrt(x * x + y * y); }
    /// Angle relative to x-axis.
    double angle() const { return std::atan2(y, x); }

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
    point r;
    r.x = 1;
    r.y = 2;
    std::cout << "r = {x:" << r.x << ", y:" << r.y << "}\n";
    return 0;
}
