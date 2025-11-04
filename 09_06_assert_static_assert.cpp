// #define NDEBUG          // This must be placed before any #include

#include <iostream>
#include <cassert>      // For asssertion
#include <cmath>        // For std::sqrt

/*
 * In our program if we have any problematic statement, then skipping such
 * statement is not the solution (using if-else).
 *
 * Also std::exit() is not the solution as if we use exit(), we will loose our
 * call stack, and any debuggin information that might help.
 * std::abort() is better option, with this we can start debugging from the
 * the point where program has aborted.
 */

/* Pre-condition, Invariants and Post-condition
 *
 * 1. Pre-condition:
 *    Is any condition that must be true before execution of some section of code.
 *    In example below if(y != 0) is the pre-condition.
 *    Pre-conditions are mostly placed at the top of the function.
 */
void printDivide(int x, int y)
{
    if(y != 0) {
        std::cout << "Division : " << double(x) / y << std::endl;
    }
    else {
        std::cout << "error: divide by zero {0}" << std::endl;
    }
}

/*
 * 2. Invariants
 *    Here, some condition must be true while some of the section of the code is
 *    executing. This is ofter used in loops.
 *
 * 3. Post-condition
 *    Here, some condition must be true after the exection of some section of
 *    the code. (I think do while is the good example)
 */

/*
 * Assertions
 * Is an expression that will be true util there is a bug in the program.
 * If the expression evaluates to true assertion does nothing and if the
 * condition evaluates to false then the error message is displayed and
 * program is terminated (via std::abort()).
 * Asserts are used to detect errors while developing and debugging.
 *
 * This error message contains:
 * 1. expression that has failed as text.
 * 2. name of the code file.
 * 3. line number of the assertion.
 *
 * Assertion are implmented via the "assert" preprocessor macro, which lives
 * in the <cassert> header.
 *
 */

/*
 * statis_assert
 * C++ have another type of assert called as static assert.
 * static assert is a type of assert that is checked at compile-time rather
 * than runtime.
 * Failing static_assert cause compile-time error.
 *
 * Unlike assert which is declared in <cassert> header, static_assert is a
 * keyword.
 *
 * syntax:
 * static_assert(condition, diagnostic_message);
 * If the condition is not true, diagnostic message is printed.
 *
 * Few conditions for using static_assert:
 * 1. As static_assert is evaluated at compile-time condition should be
 *    constant expression.
 * 2. static_assert can be placed anywhere in the code file.
 * 3. static_assert cannot be deactivated as assert.
 * 4. as compiler does the evaluation, there is no runtime cost.
 *
 * since C++17, diagnostic_message is optional.
 * -> preffer, static_assert over assert.
 */
const int tr = 1;
const int fal = 0;

static_assert(tr, "True is true!");
static_assert(fal, "Fals is false!");

double calculateTimeUtilObjectHitsGround(double initialHeight, double gravity)
{
    assert(gravity > 0.0);      // The object will not react the ground uless
                                // there is positive gravity.

    if(initialHeight < 0.0) {
        // Object is already on the ground, or buried.
        return 0.0;
    }

    return std::sqrt((2.0 * initialHeight) / gravity);
}



/*
 * Assertions VS Errors handling
 *
 * Assertions are used to detect programming errors during development by
 * documenting assumptions about things that should never happen.
 * Assertions do not allow the recovery from errors.
 *
 * Error handling is used when we need to gracefully handle cases that could
 * happen in a release build. This could be either recoverable or unrecoverable
 * issues.
 */

int main()
{
    // This statement will fail, "assert(gravity > 0.0)" and will print error.
    // calculateTimeUtilObjectHitsGround(10, -9.8);


    /*
     * Assertion below prints "Assertion 'temp' failed."
     * This dosent tell anything more about assertion or about state of code.
     */
    int temp = 0;
    // assert(temp);

    /*
     * Better approach
     * -> string literal always evaluates to Boolean true.
     *    This gives some additional context as to what went wrong.
     */
    assert(temp && "Temp is zero!");

    /*
     * assert macro comes with small performance cost for each assert check.
     * also assert should not be present in the production code, because we
     * have already tested our code.
     *
     * C++, comes with build in way to turn off the asserts in production code.
     * If pre-processor macro NDEBUG is defined then assert macro is disabled.
     */
    return 0;
}
