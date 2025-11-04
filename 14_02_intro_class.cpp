#include <iostream>
#include <cassert>

/*
 * Class Invariant
 *
 * Invariant -> the codition must be true while some component is executing.
 *
 * In class-type (struct, class, uninon) a class invariant is a condition
 * that must be true throughout the life time of an object in order for the
 * object to remain in a valid state.
 * The object that has violated the class-invariant is said to be in an
 * invalid state, and undefined or unexpected behaviour may result.
 */
struct Fraction {
    int numerator {1};
    int denominator {0};    // class invariant: should never be zero
};
void printFraction(const Fraction& f)
{
    assert(f.denominator && "Denominator is zero!");
    std::cout << "Fraction: " << f.numerator / f.denominator << std::endl;
}


/*
 * Another example of class-invariant.
 * In the code below there is huge chances of class-invariants. And we are
 * relying on the user to handle this situation carefully.
 *
 * Relying on the user of an object to maintain class invariant results in
 * problems.
 *
 * To overcome this, we need to code such that objects shouldn't be put
 * into invalid state, or can signal immidiately if it is.
 *
 * Structs dont have the mechanism required to solve this problem.
 */
struct Employee {
    std::string name;
    char firstInitial {};   // should always hold the first char of name
};


/*
 * Class
 *
 * 1. Class is a program defined data type which was developed by Stroustrup
 *    to overcome the common pitfalls of Struct. (specially class-invariant)
 * 2. Class is program-defined type hence its definition should be available
 *    before using it.
 * 3. Classes are very similar to struct, such that we can use struct at the
 *    place of class. (Very minute variations are there)
 *
 * Most of the standard library is Classes
 * std::string and std::string_view are classes.
 * Classes are the heart of C++ that why it is called as "C with class".
 */
class Employee {
    std::string name;
}

int main()
{
    Fraction fr1 {1, 0};    // class-invariant: object fr1 is in invalid state.
    printFraction(fr1);     // This will print assertion error.
    return 0;
}
