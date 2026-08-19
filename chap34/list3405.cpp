/** Listing 34-5. Constructors for Class point */
#include <iostream>

struct point {
    point(): point { 0.0, 0.0 } { }
    point(double x, double y): x_ { x }, y_ { y } { }
    point(point const &pt): point { pt.x_, pt.y_ } { }
    double x_;
    double y_;
};
int
main()
{
    point p1;
    point p2 { 1.0, 2.0 };
    std::cout << "p1=" << p1.x_ << ',' << p1.y_ << '\n';
    std::cout << "p2=" << p2.x_ << ',' << p2.y_ << '\n';
    return 0;
}
