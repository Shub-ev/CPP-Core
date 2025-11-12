#include <iostream>

/*
 * Basic Exception Handling
 *
 * Exceptions in C++ are implemented using three keywords that work in
 * conjunction with each other: throw, try, and catch.
 */

/*
 * 1. Throwing exceptions.
 *
 * In C++, a throw statement is used to signal that an exception or error case
 * has occurred. Signaling that an exception has occurred is also commonly
 * called "raising an exception".
 *
 * To use a throw statement, simply use the throw keyword, followed by a value
 * of any data type you wish to use to signal that an error has occurred.
 * Typically, this value will be an error code, a description of the problem,
 * or a "custom exception class".
 * 1. throw -1; // throw a literal integer value
 * 2. throw ENUM_INVALID_INDEX; // throw an enum value
 * 3. throw "Can not take square root of negative number";
 *    // throw a literal C-style (const char*) string
 * 4. throw dX; // throw a double variable that was previously defined
 * 5. throw MyException("Fatal Error"); // Throw an object of class MyException
 */

/*
 * 2. Try Block.
 *
 * Throwing exceptions is only one part of the exception handling process.
 * In C++, we use the try keyword to define a block of statements (called a try
 * block). The try block acts as an observer, looking for any exceptions that
 * are thrown by any of the statements within the try block.
 *
 * try {
 *      // Statements that may throw exceptions you want to handle go here
 *      throw -1; // here's a trivial throw statement
 *  }
 *
 * Note that the try block doesn’t define HOW we’re going to handle the
 * exception. This block just holds the statements which can thow an exception.
 */

/*
 * 3. Handling Exception.
 *
 * Handling exceptions is the job of the catch block(s). The catch keyword is
 * used to define a block of code (called a catch block) that handles exceptions
 * for a single data type.
 *
 * catch (int x)
 * {
 *      // Handle an exception of type int here
 *      std::cerr << "We caught an int exception with value" << x << '\n';
 * }
 *
 * Try blocks and catch blocks work together -- a try block detects any exceptions
 * that are thrown by statements within the try block, and routes them to a catch
 * block with a matching type for handling.
 *
 * A try block must have at least one catch block immediately following it, but
 * may have multiple catch blocks listed in sequence.
 *
 * Once an exception has been caught by the try block and routed to a matching
 * catch block for handling, the exception is considered handled. After the
 * matching catch block executes, execution then resumes as normal, starting
 * with the first statement after the last catch block.
 *
 * Catch parameters work just like function parameters, with the parameter being
 * available within the subsequent catch block. Exceptions of fundamental types
 * can be caught by value, but exceptions of non-fundamental types should be
 * caught by const reference to avoid making an unnecessary copy (and, in some
 * cases, to prevent slicing).
 *
 * No type conversion is done for exceptions (so an int exception will not be
 * converted to match a catch block with a double parameter).
 */

/*
 * Important:
 * 1. When an exception is raised (using throw), the running program finds the
 *    nearest enclosing try block (propagating up the stack if necessary to
 *    find an enclosing try block to see if any of the catch handlers attached
 *    to the try block can handle that type of exception. If so, execution jumps
 *    to the top of the catch block, the exception is considered handled.
 *
 * 2. If no appropriate catch handlers exist in the nearest enclosing try block,
 *    the program continues to look at subsequent enclosing try blocks for a
 *    catch handler. If no appropriate catch handlers can be found before the end
 *    of the program, the program will fail with a runtime exception error.
 *
 * 3. If an exception is routed to a catch block, it is considered “handled”
 *    even if the catch block is empty.
 */

/*
 * There are four common things that catch blocks do when they catch an exception:
 *
 * 1. catch blocks may print an error (either to the console, or a log file) and
 *    then allow the function to proceed.
 * 2. catch blocks may return a value or error code back to the caller.
 * 3. a catch block may throw another exception. Because the catch block is
 *    outside of the try block, the newly thrown exception in this case is not
 *    handled by the preceding try block -- it’s handled by the next enclosing
 *    try block.
 * 4. a catch block in main() may be used to catch fatal errors and terminate
 *    the program in a clean way.
 */
int main()
{
    try
    {
        // Statements that may throw exceptions you want to handle go here
        throw -1; // here's a trivial example
    }
    catch (double) // no variable name since we don't use the exception itself in the catch block below
    {
        // Any exceptions of type double thrown within the above try block get sent here
        std::cerr << "We caught an exception of type double\n";
    }
    catch (int x)
    {
        // Any exceptions of type int thrown within the above try block get sent here
        std::cerr << "We caught an int exception with value: " << x << '\n';
    }
    catch (const std::string&) // catch classes by const reference
    {
        // Any exceptions of type std::string thrown within the above try block get sent here
        std::cerr << "We caught an exception of type std::string\n";
    }

    // Execution continues here after the exception has been handled by any of the above catch blocks
    std::cout << "Continuing on our merry way\n";

    // Exceptions are handled immediately
    try
    {
        throw 4.5; // throw exception of type double
        std::cout << "This never prints\n";
    }
    catch (double x) // handle exception of type double
    {
        std::cerr << "We caught a double of value: " << x << '\n';
    }

    return 0;
}
