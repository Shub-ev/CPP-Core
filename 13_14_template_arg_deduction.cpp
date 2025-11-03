#include <iostream>
#include <utility>

/*
 * We will discuss how Template types gets deduced.
 * Compiler deduces the type of template from the types of the
 * Object's initializer. This is called "class template argument deduction".
 * or CTAD.
 */

/*
 * Aggregate class template:
 * 1. Have no private or protected non-static members.
 * 2. No user-declared or user provided constructors.
 * 3. No virtual function or virtual base address.
 * 4. No base classes.
 *
 * CTAD (class template arguments deduction) does not support for aggregate
 * class templates on C++17 and before.
 */

template <typename T, typename U>
struct AGG_Struct {
    T a {};
    U b {};
};

/*
 * Type template parameters with default values.
 * As we can have default values for function parameters, we can also give
 * template parameters default values.
 */
template <typename T = int, typename U = int>
struct Pair {
    int a {};
    int b {};
};

/*
 * We can provide deduction guide for compiler.
 * which tells compiler how to deduce the template arguments for a given
 * class template.
 */
template <typename T, typename U>
AGG_Struct(T, U) -> AGG_Struct<T, U>;

int main()
{
    std::pair<int, int> p1 {1,2};
    // explicitly specify class template std::pair<int, int>

    std::pair p2 {1,2};
    // CTAD used to deduce std::pair<int, int> from initializers.

    /*
     * CTAD (class template argument deduction).
     * Is only performed if no template argument list is present.
     * Hence following are errors:
     * 1. std::pair<> p1 {1, 2};
     * error: too few template arguments, both arguments not deduced.
     *
     * 2. std::pair<int> p2 {1, 2};
     * error: too few template arguments, second argument not deduced.
     */

    // We can use literal suffixes to change the deduced types
    std::pair p3 {1u, 2u};
    // deduced to std::pair<unsigned int, unsinged int>

    /*
     * C++17 and before cannot perform CTAD, on aggregate class
     * templates.
     *
     * Code below will not compile on C++17 compiler.
     * We need to compile it as:
     * g++ file_name.cpp -std=c++20 and onwards.
     */
    AGG_Struct agg {1, 2};
    /*
     * Now we are using deduction guide, so above code will work fine.
     * And will use CTAD to deduce class template types from the
     * initializers.
     */

    Pair p4;            // Uses default Pair<int, int>
    return 0;
}
