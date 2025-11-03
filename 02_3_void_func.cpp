#include <iostream>

/*
 * Void Function
 * 1. A function that does not return a value is called "non-value returning function".
 * 2. Void function don't need return statement, it automatically return to caller.
 *    Still we can use return to return before the end of function.
 * 3. Void function cannot be used in expression that require value.
 * 4. Returning a value from void function is a compile error.
 */
void temp() {}

/*
 * **   It is a common misconception that main is always the first function that executes.
 *      Global variables are initialized prior to the execution of main. 
 *      If the initializer for such a variable invokes a function, then 
 *      that function will execute prior to main.   **
 */


int main()
{
    //std::cout << temp() << std::endl;
    return 0;
}
