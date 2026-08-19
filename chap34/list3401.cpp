/** Listing 34-1. Class Definition for a Cartesian Point */
#include <iostream>

struct point {
    double x;
    double y;
};

int
main()
{
    point p { 1.0, 2.0 };
    std::cout << "p = {x:" << p.x << ", y:" << p.y << "}\n";
    return 0;
}
