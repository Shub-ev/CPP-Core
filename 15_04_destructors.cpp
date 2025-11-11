#include <iostream>

/*
 * Class Destructors
 *
 * Issue: classes that use a resource (memory, database, network) often need
 *        to be closed explicitly before the class object is destroyed. Or also
 *        we want to perform some operations before deleting the object.
 *
 * For such operations relying over users is not a good option.
 * As we have constructors for initializing the data members of the class type
 * while creating the object.
 * 
 * We also have another special member function that will be called automatically
 * when object of non-aggregate class type is destroyed. This function is called
 * as "destructor".
 * "Destructors" are designed to allow a class to do any necessary clean up
 * before an object is destroyed.
 *
 * Destructor Naming:
 * 1. Must have same name as class, preceded by a tilde (~).
 * 2. Can not take arguments.
 * 3. Has no return type.
 *
 * Other Rules:
 * 1. Each class can have only one destructor.
 * 2. Generally we should not explicitly call the destructors, as it is called
 *    automatically.
 * 3. Destructors can safely call other member functions since the object isnt
 *    destroyed until after the destructor executes.
 * 4. Static variables including static local and global are constructed at
 *    program startup and destroyed at program shutdown.
 * 5. If any class type dont have user defined destructor, the compiler will
 *    generate a destructor with an empty body. If your class does not need
 *    any explicit cleanup then there is no need to provide user defined
 *    destructor.
 *
 *
 * Warning: std::exit() can be used to terminate the program immidiately. So
 *          when we use exit() program just terminates.
 *          Local variables are not destroyed first, and because of this, no
 *          destructors will be called.
 *
 *          Unhandled exceptions also cause the teminate program and does not
 *          let the stack to "unwind". If stack unwinding does not happen, dest.
 *          will not be called prior to the termination of the program.
 */

class Simple
{
    private:
        int m_id {};

    public:
        Simple(int id):
            m_id(id)
        {
            std::cout << "Constructing Simple: " << m_id << std::endl;
        }

        ~Simple()
        {
            std::cout << "Destructing Simple: " << m_id << std::endl;
        }
};

int main()
{
    Simple simple1 { 1 };

    {
        Simple simple2 { 2 };
    }       // simple2 dies here
    return 0;
}           // simple1 dies here

/*
 * Here for each object is getting destroyed, "destructor" is called.
 */
