#include <iostream>

/*
 * Const class object
 *
 * 1. As we can make fundamental data types const using const qualifier and we
 *    should initialize them at the time of declaration, we can also make class
 *    object const in the same way and these object also must be initialized at
 *    the time of creation.
 *
 * 2. Modifying the data members of const objects is disallowed. This includes
 *    updating data-members directly or calling member functions to update.
 *
 * 3. Constant object may not call non-constant member function. 
 */

struct Student {
    std::string name;
    int age;

    void incrAge()
    {
        age++;
    }

    void print()
    {
        std::cout << "Name: " << name << "\nAge: " << age << std::endl;
    }
};

int main()
{
    Student student1 {"Shubham", 21};
    student1.print();
    student1.incrAge();
    student1.print();

    // const Student student2;  // error: uninitialized 'const student2'
    const Student student2 {"Hari", 23};
    // student2.incrAge();      // error: passing 'const student' as 'this'
                                // argument discard qualifiers

    /* 
     * We cannot call non-const member functions from const object.
     * To overcome this issue we need to declare member function as constant.
     * "const member functions":
     * 1. cannot call non-constant member functions.
     * 2. cannot modify the object.
     * 3. const member function can modify non-member variables such as local
     *    variables and function parameters.
     * 4. const member function can also modify the objects that are not
     *    implicit object.
     * 5. const member functions can be called on both const and non-const
     *    objects.
     * 6. If member function dosent modify anything then that function should
     *    be made const so it can be called by const and non-const object.
     * 
     * constructors may not be made const, as they modify the data members.
     */
    student2.print();           // same as above error will be here
                                // even print dosent try to modify any data
    return 0;
}
