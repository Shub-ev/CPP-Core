#include <iostream>

/*
 * Dynamic memory allocation.
 *
 * C++ supports 3 types of memory allocations:
 * 1. static memory allocation: For static and global variables.
 * 2. automatic memory allocation: For local variables and function parameters.
 * 3. Dynamic memory allocation.
 *
 * Both static and auto have 2 things in common:
 * 1. Size of the variable must be known at compiler time.
 * 2. Mem. allocation and deallocation happens automatically.
 *
 * In C++, to allocate single variable dynamically, we use the scalar (non-array)
 * form of the new operator.
 *
 * Node: Accessing heap allocated objects are generally slower than accessing
 *       stack allocated objects.
 *       Heap allocated objects are typically accessed via pointer. This requires
 *       2 steps. one to get the address of the object and another to get the
 *       value.
 *
 * Unlike automatic or static program itself is responsible for requesting
 * and disposing of dynamically allocated memory.
 */

int main()
{
    // dynamically allocates an int and discard the result
    new int;
    // here we are requesting an integer worth of memory from the operating sys.
    // The new operator create the object using that memory, and then returns
    // a pointer containing the address of the memory that has been allocated.

    int *num { new int };
    *num = 10;

    // When we dynamically allocate a variable, you can also initialize it via
    // direct initialization or uniform initialization.
    int *num1 { new int (5)}; // use direct initialization
    int *num2 { new int {6}}; // use uniform initialization

    /*
     * Deleting a single variable.
     * when we are done with dynamically allocated variable we need to
     * explicitly tell C++ to free the memory for reuse.
     *
     * For single variables, this is done via the scalar form of the "delete"
     * operator.
     *
     * Delete operator does not actually delete anything. It simply returns the
     * memory being pointed to back to the OS. OS is then free to reassign
     * that memory to another application.
     */
    delete num1;    // return the memory pointed by the num1 to the OS
    num1 = nullptr; // set num1 to the nullptr

    /*
     * Dangling Pointer
     *
     * C++ does not guarantees about what will happen to the contents of
     * deallocated memory.
     * A pointer that is pointing to deallocated memory is called a "dangling
     * pointer". Dereferencing or deleting a dangling pointer will lead to
     * undefined behaviour.
     *
     * Best Practices:
     * 1. Avoid multiple pointer pointing as the same piece of dynamic memory.
     * 2. When delete a pointer and that pointer is not going out of scope
     *    immediately afterward, set the pointer to nullptr.
     */
    std::cout << *num2 << std::endl;
    delete num2;
    std::cout << *num2 << std::endl;        // undefined behaviour
    delete num2;                            // undefined behaviour

    /*
     * Operator new can fail!
     *
     * In rare cases while using new, OS may not have any memory to grant the
     * request with.
     * By default if new fails, "bad_alloc" exception is thrown. If this
     * exception isn't properly handled, the program will simply terminate.
     *
     * In many cases handling new throwing exception is undesirable, so there's
     * an alternate form of new that returns the "nullptr" if memory cant be
     * allocated.
     * This is done by adding the constant "std::nothrow" between the new keyword
     * and allocation type.
     */
    int *num3 { new (std::nothrow) int };   // value will be set to null if
                                            // allocation fails.


    /*
     * Null pointers and dynamic memory allocations.
     *
     * Null pointers are typically useful when dealing with dynamic memory
     * allocation.
     *
     * While deleting if ptr has dynamic memory then,
     * delete ptr;                          // will deallocate memory
     * but if prt is null then nothing will happen.
     */

    /*
     * Memory leaks
     *
     * Dynamically allocated memory with no pointer pointing to it is a form
     * of memory leak.
     * As below num4 is local to its scope once it is completed we dont have
     * access to the dynamically allocated memory and we cannot free it.
     * It will be there throughout the program. This is called "memory leak".
     *
     * At the end of the program OS will free and reclaim all the memory.
     */
    {
        int *num4 { new int {5} };
    }
    // std::cout << *num4 << std::endl;     // error: "num4" was not declared
                                            // in this scope.
    return 0;
}
