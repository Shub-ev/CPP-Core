#include <iostream>

/*
 * C++ have 2 compund types:
 * 1. struct
 * 2. class
 *
 * struct is a class type so anything that applies to class aplies to struct
 * As per best practice program-defined types should have first letter capital
 */

/*
 * 1. Struct should end with semicolon as we are difining a program-defined type.
 * 2. Variables that are part of struct are called "data members" or "member variables"
 * 3. A member is a function or variable or type that belongs to a struct.
 * 4. We have {} (value-initialization) after each variable so all variables of struct
 *    should be value value-initialization whenever instantiated.
 * 5. Below is just stuct type definition, no memory is allocated here.
 * 6. As "Student" is now program-defined type we can create variables of same type.
 */
struct Student {
    std::string name {};  // value-initialization with default values
    int age {};
};

int main()
{
    /*
     * Define variable of type Student.
     * Here student is Student struct object which hold 2 member variables.
     */
    Student student1 {"Shubham Gharage", 21};

    // To access the member variables of struct we use "member selection operator (.)".
    std::cout<<student1.name<<std::endl;
    return 0;
}
