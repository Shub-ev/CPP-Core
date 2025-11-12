#include <iostream>

/*** Rework needed ***/

/*
 * Value catagories:
 * is a property of expressions that helps determinine whether an expression
 * resolves to value, function or object.
 *
 * Prior to C++11, only one type of references existed and so it was just called
 * a "reference". In C++11 its called an l-value reference. L-value references
 * can only be initialized with modifiable l-values.
 *
 * C++11 Added new type of reference called an "r-value" reference. This
 * reference can be initialized by rvalues only.
 *
 * As l-value reference is created using single ampersand &, r-value reference
 * needs to be created using double ampersand.
 */
int main()
{
    int x;
    int& lref {x};
    int&& rref {x};

    return 0;
}
