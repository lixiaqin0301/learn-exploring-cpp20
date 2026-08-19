/** @file list3403.cpp */
/** Listing 34-3. Using a Class and Its Members */
#include <iostream>

struct point {
    double x;
    double y;
};

int
main()
{
    point origin {}, unity {};
    origin.x = 0;
    origin.y = 0;
    unity.x = 1;
    unity.y = 1;
    std::cout << "origin = {x:" << origin.x << ", y:" << origin.y << "}\n";
    std::cout << "unity  = {x:" << unity.x << ", y:" << unity.y << "}\n";
    return 0;
}
