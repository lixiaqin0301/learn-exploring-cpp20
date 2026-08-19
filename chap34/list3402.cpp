/** Listing 34-2. Multiple Data Members in One Declaration */
#include <iostream>

struct point {
    double x, y;
};

int
main()
{
    point p { 1.0, 2.0 };
    std::cout << "p={" << p.x << "," << p.y << "\n";
    return 0;
}
