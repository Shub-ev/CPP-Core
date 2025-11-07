#include <iostream>

/*
 * Constructors
 *
 * When class type is aggregate, we can use aggregate list to initialize class.
 * Aggregate initialization does memberwise initialization.
 * But aggregate initialization dosent work with classtypes with private data
 * members.
 * So, we need to use "constructor".
 * 1. Constructor is a special member function that is automatically called
 *    "after" a non-aggregate class type object is created.
 * 2. When a non-aggregate class type object is defined, the compiler looks for
 *    an accessible constructor that is a match for initialization values
 *    provided by the caller.
 * 3. When accessible constructor is found, then memory for the object is
 *    allocated, then constructor function will be called.
 *    If no matching function is found then compiletime error will be generated
 * 4. Contructor do not create object. Compiler set up the memory allocation
 *    for the object prior to the constructor call.
 *
 * 5. Constructors perform 2 functions:
 *    A. perform initialization of any member variables. (via member
 *       initialization list)
 *    B. They may perform other setup functions. (error-checking or database etc)
 * 6. After the constructor finishes executing, object has been "constructed".
 *
 * Note: Aggregates are not allowed to have constructors. and if we add constructor
 *       to an aggregate, it is no longer an aggregate.
 */

/*
 * Naming constructors
 *
 * 1. constructors must have same name as class. For template classes, this name
 *    excludes the template parameters.
 * 2. constructors have no return type. (not even void)
 * 3. constructor should not be const. Constructor needs to be able to initialize
 *    the object being constructed.
 * 4. const dosent apply to an object under construction, and only comes into
 *    effect after the constructor ends.
 * 5. constructors are designed to initialize an entire object at the point of
 *    initialization. setters are designed to assign a value to single data
 *    member.
 */
class Student {
    private:
        std::string m_name {};
        int m_age;

    public:
        Student (std::string name, int age)
        {
            m_name = name;
            m_age = age;
            std::cout << "Student (" << m_name << ", " << m_age 
                << ") constructor called!" << std::endl;
        }
};

int main()
{
    /*
     * Here, compiler sees the definition student1 {"Shubham", 21}
     * It search for similar constructor that will accept two int arguments.
     */
    Student student1 {"Shubham", 21};
    return 0;
}
