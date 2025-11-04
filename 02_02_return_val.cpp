#include <iostream>

/*
 * Function Return value.
 * When we write a user-defined function, we get to determine
 * whether our function will return a value back to caller or not.
 *
 * We can set what type of value is returned by the function to caller
 * my mentioning the type at the returntype place.
 * returntype function_name()
 * {
 * }
 *
 * We return value from function by using return statement.
 * Also our function can be of type void (dosen't return anything).
 *
 * While returning:
 * 1. Return expression is evaluated to produce value.
 * 2. Value produced is "copied" back to the caller.
 * 3. Function exits, and control returns to the caller.
 * 4. Function can return only a single value back to the caller. 
 * The process of returning copied value back to the caller is
 * named "return by value".
 */

int foo()
{
    return printf("Hello foo\n");
}
int ret = foo();

// fun()   // error: ISO C++ forbids declaration of 'fun' with no type.
int fun()
{
    return printf("Hello");
}

// This returns garbage
int fun1()
{

}

/*
 * main() in C++ requires:
 * 1. Return int.
 * 2. explicit function calls to main are disallowed. (C allows)
 * 3. Return 0 if no return statement is provided.
 * void main()              // '::main' must return int
 */
int main()
{
    std::cout<< "start of main\n" << std::endl;
    std::cout << fun() << std::endl;

    std::cout << fun1() << std::endl;

    //std::cout << temp() << std::endl;
    return 0;
}
