#include <iostream>

/*** ADD CODES FROM ARTICLE ***/

/*
 * Exceptions, functions, and stack unwinding.
 *
 * 1. Throwing exceptions from a called function.
 * The throw statements do NOT have to be placed directly inside a try block.
 * Instead, exceptions can be thrown from anywhere in a function, and those
 * exceptions can be caught by the try block of the caller (or the caller’s
 * caller, etc…). When an exception is caught in this manner, execution jumps
 * from the point where the exception is thrown to the catch block handling the
 * exception.
 */

/*
 * 2. Exception handling and stack unwinding
 *
 * When an exception is thrown, the program first looks to see if the exception
 * can be handled immediately inside the current function.
 *
 * If not, the program next checks whether the function’s caller (the next
 * function up the call stack) can handle the exception.
 *
 * In order for the function’s caller to handle the exception, the call to the
 * current function must be inside a try block, and a matching catch block must
 * be associated. If no match is found, then the caller’s caller (two functions
 * up the call stack) is checked.
 *
 * The process of checking each function up the call stack continues until
 * either a handler is found, or all of the functions on the call stack have
 * been checked and no handler can be found.
 *
 * If a matching exception handler is found, then execution jumps from the point
 * where the exception is thrown to the top of the matching catch block. This
 * requires unwinding the stack (removing the current function from the call stack)
 * as many times as necessary to make the function handling the exception the top
 * function on the call stack.
 *
 * When the current function is removed from the call stack, all local variables
 * are destroyed as usual, but no value is returned.
 */

/*
 * Some important things.
 *
 * 1. the immediate caller of a function that throws an exception doesn’t have
 *    to handle the exception if it doesn’t want to.
 *
 * 2. if a try block doesn’t have a catch handler for the type of exception
 *    being thrown, stack unwinding occurs just as if there were no try block
 *    at all.
 *
 * 3. if a function has a matching catch block but the call to the current
 *    function did not occur within the associated try block, that catch block
 *    isn’t used.
 *
 * 4. once a matching catch block executes, control flow proceeds as normal,
 *    starting with the first statement after the last catch block.
 */

int main()
{
    return 0;
}
