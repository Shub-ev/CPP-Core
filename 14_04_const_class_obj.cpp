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

    student2.print();           // same as above error will be here
                                // even print dosent try to modify any data

    return 0;
}
