#include <iostream>

/*
 * Default member initialization in struct.
 * 1. We can provide value-initialization for each member of struct.
 * 2. If we provide value-initialization for non-static member then
 *    it is called as "non-static member initialization".
 * 3.
 */

struct Something {
    int a;                      // No default value (bad)
    int b {};                   // value-initialization by default
    int c {3};                  // explicit default value
};

int main()
{
    Something s1;               // here s1.a is un-initialized, s1.b is 0, s1.c is 3

    // Explicit initialization
    Something s2 {1, 2, 3};     // here s2.a is 1, s2.b is 2, s2.c is 3

    // Missing initializers in initializer list
    Something s3 {};            // here s3.a is value-initialized, s3.b is default (0),
                                // s3.c is 3

    return 0;
}
