#include <stdio.h>

/*
 *  As of G++23
 *  C++ have 92 reserved words / keywords
 */

int main()
{
    /*  This will not generate compile-time error.
     *  But modern compilers may generate warning!
     *
     *  ** On GCC compiler code with -Wall to get the warning! **
     *
     *  If we want unused variable and still want compiler not to complaint,
     *  we can use [[maybe_unused]] attribure (C++17)
     */
    int a = 10;                         // Will Generate Warning

    [[maybe_unused]] int b = 20;        // Will not Generate Warning

    return 0;
}
