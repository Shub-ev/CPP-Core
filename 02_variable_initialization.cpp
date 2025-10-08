#include <stdio.h>

/*
 *  We can initialize a variable by following methods.
 *
 *  1. Copy initialization
 *  2. Direct initialization
 *  3. Direct-List initialization
 *  4. Value initialization
 *
 */

int main()
{
    /*  1. Copy initialization
     *
     *  Inherited from C language
     *  Copies value of right hand side into the var. of left hand
     *  This initialization is not prefered because of its inefficiencies for
     *  some complex type of type.
     */
    int a = 10;


    /*  2. Direct initialization
     *  Similar to Copy initialization
     */
    int b (10);


    /*  3. List-Initialization
     *
     *  Most prefered and also supported by Stroustrup
     *
     *  ** List initialization dis-allow narrowing of data types **
     *
     *  Two types:
     *      A. Direct-List initialization
     *      B. Copy-list initialization
     */
    int c {10};
    int d = {20};
    // int e {4.5};  this will generate error in List-Initialization


    /*  4. Value initialization
     *
     *  In most cases this initialize variable with 0 (so called zero-initialization)
     */
    int e {};   // Here e is initialized with 0;
    // printf("%d", e);

    return 0;
}
