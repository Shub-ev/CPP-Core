#include <iostream>

/*
 * Return by Reference and Address
 *
 * When passing an argument by value, a copy of that argument is made into
 * the function parameter.
 * This is okay with fundamental types, but it is preformance expensive for
 * class types.
 *
 * Instread, we can do pass by reference or by address, which is more
 * preformance friendly.
 *
 * Same situation when returning by value a copy of the return value is
 * provided to the caller. If the return type of function is class type then
 * this is also performance expensive.
 *
 * So instead of returning copy of class type return value, we can return the
 * refernce of the same value. For that we need to change the return type of
 * the function to return reference type.
 *
 * 1. Objects returned by reference must exist after the function returns.
 */

std::string& getName()
{
    /*
     * String is an object.
     * So, we need to make it static because it must be alive once function
     * returns, or we will get warning and segmentation fault.
     *
     * If string was non-static then that string object would be local variable
     * with automatic duration. Results in dangling pointer to the caller.
     */
    static std::string str { "shubham" };
    return str;
}

/*
 * 1. We can return reference to integer literals.
 * 2. Here, function returnInt() is returning integer 5.
 * 3. But, the return type is const int reference hence function returns
 *    "temporary reference bound to a temporary object holding value 5". This
 *    returned reference is then copied into the temporary reference of the
 *    caller.
 * 4. The temporary object then goes out of scope. Result in dangling pointer
 *    to the caller.
 * 5. By the time temporary reference in the scope of the caller is bound to
 *    const reference variable num, it is too late to extend the lifetome of
 *    the temp object, as it is already been destroyed.
 *
 * 6. Lifetime extension does not work across the function boundries.
 * 7. Dont return non-constant static variable by reference. Because if we have
 *    multiple non-constant references of any object then change by one
 *    reference will result in change of all the reference links, as original
 *    object is changed.
 * 8. If a function returns a reference, and we are trying to assign/initialize
 *    a non-reference variable with a reference value then return value will
 *    be copied (as is if had beed returned by value).
 * 9. It is also valid to return reference parameters by reference.
 */
const int& returnInt()
{
    return 5;
}

const int& getId()
{
    static int set_id {0};
    ++set_id;

    return set_id;
}

/*
 * When an argument for the const reference parameter is an rvalue, it's okay
 * to return that parameter by const reference.
 * This is because rvalues are not destroyed until the end of the full
 * expression in which they are created.
 * Here,
 * we cannot have,
 * const std::string& r_string() because we want rvalue but here because of
 * above return type reference to string compiler must create temporary unnamed
 * object.
 */
std::string r_string()
{
    // Here we are returning rvalue by const reference.
    return "Hello";
}

/*
 * We can also return const reference to the rvalue, as follow.
 * This is also "lifetime extension" example.
 */
const std::string& const_r_string(const std::string& str)
{
    return str;
}


int main()
{
    std::string name { getName() };
    std::cout << name << std::endl;

    /*
     * Here,
     * first line below generates error are we are trying to store the
     * reference to temporary.
     * on the second line we will get runtime-error (segmentation fault)
     * as temporary was local and already removed.
     */
    const int& num { returnInt() };
    // std::cout << num << std::endl;

    /*
     * Here, we are initializing the get_id int variable with reference of static
     * variable. Hence value of the returned reference will be copied into the
     * get_id.
     */
    int get_id { getId() };

    /*
     * Here, we are using rvalue string returned by a function to initialize
     * srt variable. After assigning the value expression is completed, then
     * this rvalue string is deleted.
     */
    std::string str{ r_string() };
    std::cout << str << std:: endl;

    // Now this const_r_string returns const reference to string rvalue.
    std::string str2 { const_r_string( r_string() ) };
    std::cout << str2 << std::endl;

    return 0;
}
