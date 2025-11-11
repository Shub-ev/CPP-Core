#include <iostream>

/*
 * Destructor.
 *
 * Destructors are special kind of member functions executes when object is
 * being destroyed. This helps in cleanup of object.
 *
 * When, object goes out of the scope or dynamically allocated object is
 * explicitly deleted using delete operator, destructor is automatically called
 * to do any necessary cleanup.
 *
 * Mostly implicit destructor provided by the compiler is prefered, but if our
 * object holds any resources then we have to explicitly provide the destructor.
 *
 * A class can have only single destructor.
 * Gerenerally, we should not call destructor explicitly.
 *
 * Global variables are constructed before main and destroyed after main.
 *
 */

/*
 * RAII (Resource Acquisition Is Initialization)
 *
 * is a programming technique whereby resource use is tied to the lifetime of
 * objects with automatic duration. In C++ RAII is implemented via classes with
 * constructors and destructors. Here, resources are provided to the object in
 * its constructor, then these resources are used by the object throught its
 * life time. The resource then released at end of life through destructor.
 * This prevents memory leak and bugs.
 *
 * Node: When we call std::exit() no destructor is called and program terminate
 */

int main()
{
    return 0;
}
