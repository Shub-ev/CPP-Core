#include <iostream>

/*
 * Function Parameters
 * To perform operations on the data, function need to access that
 * data. To do this we need to pass this data to function.
 *
 * We pass data to function as arguments, function catch this data
 * into function parameters.
 * -> void temp(int a, int b) {}
 *
 * Here, a and b are function paramters. There are local variables
 * of the function.
 *
 * When ever we pass arguments to this functions as:
 * temp(10, 20);
 *
 * These arguments are copied into function parameters. This process is
 * called as "pass by value". Number of arguments should match with the
 * number of parameters. (Types also should match)
 *
 * We can also use return value of function as argument to another function.
 * If we have any expression as argument then that argument is first resolved
 * then the result is passed to the function.
 *
 * If we have:
 * add(2, multiply(3,4));
 * then, first 2 will be copied into parameter of add, then multipy will be
 * resolved (called) and its return value is used as second argument.
 */


/*
 * Unreferenced Parameters
 * Parameters that are not used in the body of the function. These are called
 * "unreferenced parameters.".
 *
 * In this case compiler may warn about declared but never used variable.
 */
void dosomething(int count)
{
    printf("Do nothing\n");
}

/*
 * Unnamed function
 * Function where we are not going to use the parameter but parameter should
 * exists, we can use "unnamed parameter".
 */
void dosomething2(int)
{
    printf("Again do nothing\n");
}

int main()
{

    return 0;
}
