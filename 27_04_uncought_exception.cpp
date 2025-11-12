#include <iostream>

/*
 * Uncought Exceptions and catch-all handlers
 */

/*
 * 1. Uncaught exceptions
 *
 * When a function throws an exception that it does not handle itself, it is
 * making the assumption that a function somewhere down the call stack will
 * handle the exception.
 *
 * When no exception handler for a function can be found, std::terminate() is
 * called, and the application is terminated.
 *
 * In such cases, the call stack may or may not be unwound! If the stack is not
 * unwound, local variables will not be destroyed, and any cleanup expected upon
 * destruction of said variables will not happen!
 *
 * Note:
 * Although it might seem strange to not unwind the stack in such a case, there
 * is a good reason for not doing so. An unhandled exception is generally something
 * you want to avoid at all costs. If the stack were unwound, then all of the
 * debug information about the state of the stack that led up to the throwing of
 * the unhandled exception would be lost! By not unwinding, we preserve that
 * information, making it easier to determine how an unhandled exception was thrown,
 * and fix it.
 */

/*
 * C++ provides us with a mechanism to catch all types of exceptions. This is
 * known as a catch-all handler.
 *
 * A catch-all handler works just like a normal catch block, except that instead
 * of using a specific type to catch, it uses the ellipses operator (…) as the
 * type to catch. For this reason, the catch-all handler is also sometimes called
 * an “ellipsis catch handler”.
 *
 * The catch-all handler must be placed last in the catch block chain. This is
 * to ensure that exceptions can be caught by exception handlers tailored to
 * specific data types if those handlers exist.
 *
 * If your program uses exceptions, consider using a catch-all handler in main,
 * to help ensure orderly behavior if an unhandled exception occurs.
 */

/*
 * Debugging unhandled exceptions
 *
 * Unhandled exceptions are an indication that something unexpected has happened,
 * and we probably want to diagnose why an unhandled exception was thrown in the
 * first place. Many debuggers will (or can be configured to) break on unhandled
 * exceptions, allowing us to view the stack at the point where the unhandled
 * exception was thrown. However, if we have a catch-all handler, then all
 * exceptions are handled, and (because the stack is unwound) we lose useful
 * diagnostic information.
 *
 * Therefore, in debug builds, it can be useful to disable the catch-all handler.
 * We can do this via conditional compilation directives.
 */

void try1()
{
    try {
        throw 5;
    } catch (double d) {
        std::cout << "Cought double exception!" << std::endl;
    } catch (...) {
        std::cout << "Cought undetermined type of exception!" << std::endl;
    }
}

int main()
{
    try1();
    return 0;
}
