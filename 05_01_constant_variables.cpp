#include <iostream>

/*
 * C++ supports 2 types of constants:
 * 1. Named constant.
 *    Named constants are values associated with identifiers. Also called
 *    as symbolic constants.
 * 2. Literal constant.
 *    constant values that are not associated with identifiers.
 */

/*
 * 1. Named Constants
 * There are three ways to define names constant
 * A. Constant Variables.
 * B. Objects-like macros with substitution text. (Macros)
 * C. Enumerated constants. (Unscoped Enum)
 */

/*
 * A. Const Variable.
 * Most common constant declaration.
 *
 * 1. To declare variable const we put const qualifier before the type.
 * 2. In C++ we can put const before or after the type but putting before
 *    is more safe to avoid few special cases.
 * 3. Const variables needs to be initialized at the time of declaration.
 * 4. Const variables can be initialized from other variables including
 *    non-constant ones.
 * 5. Function parameters also can be const and we dont have to initialize
 *    them. But, also function parameters are pass by value so even if its
 *    value is changed its okay.
 *    -> So, dont use const with "value parameters".
 * 6. Function's return value can also be const, but for fundamental types
 *    const qualifier is simply ignored. (may generate warning)
 *    -> Don't use const with return values.
 */
const double kGravity {9.8};     // type of gravity is "const double"
// const int kGap;               // error: uninitialized "const gap"

const int fun1(const int temp) {
    std::cout << "Function fun1" << std::endl;
    return 10;
}

/*
 * B. Object-like macro with substitution text.
 * 

int main()
{
    return 0;
}
