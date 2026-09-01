/** Listing 41-5. Generating Unique Identification Numbers */
#include <iostream>

int
generate_id()
{
    static int counter { 0 };
    ++counter;
    return counter;
}

int
main()
{
    std::cout << generate_id() << "\n";
    return 0;
}
