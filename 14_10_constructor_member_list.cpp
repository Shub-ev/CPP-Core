#include <iostream>

/*
 * Constructor member initializer list
 *
 * Even constructor to initialize members, we can use "member initializer list"
 * This is different than "initializer list" we used to initialize aggregates.
 *
 * 1. Member initialiser list is defined after the constructor parameters.
 *    It begins with ':' and then lists each member to initialize along with
 *    the initialization value for that variable separated by ','.
 * 2. Must use a direct form of initialization here(preferably using braces, but
 *    parentheses works as well). Copy initialization will not work here.
 * 3. Also member initializer list does not end on semicolon.
 * 4. C++, doesnt care about position of simicolor, sequence of members and
 *    whitespaces.
 *    Class_name(para1, para2) : member1(para1), member2(para2) {}
 *    Thats it
 * 5. As per C++ standard, members in the initializer list will be initialized
 *    in the sequence of they are defined, and sequence of member initializer
 *    list dosent matter.
 * 6. Hence from 4 and 5 we should initialize members using list as per the
 *    sequence of definition.
 */

/*
 * Member initializer list vs default member initializer.
 *
 * 1. If member is listed in member initializer list, then that initialization
 *    value is used.
 * 2. if member has a default member initiazer, that initialization value is
 *    used.
 *    int m_x{};        // default member initializer (will be ignored)
 * 3. otherwise, the member is default-initialized.
 *    int m_x(10);      // default member initializer (will be used)
 */

/*
 * Constructor function bodies.
 *
 * 1. We left bodies of most of the constructor functions empty becase we use
 *    constructor functions to initialize the data members.
 * 2. Also, statements in the constructor body will be executed after the
 *    execution of initializer list. Hence we can add some setup, or
 *    other operations inside function body.
 */

class Temp{
    private:
        int m_x {};
        int m_y {};

    public:
        Temp(int a, int b)
        {
            // This is assignments and not initialization, this is simpel but
            // Where we need to initialize const data members this will not work.
            // So member initializer list is used.
            m_x = a;
            m_y = b;
        }
}

/*
 * 1. Once member initialzer list has finished executing object is considered
 *    to be initialized.
 * 2. Once the constructor body has finished executing, the object is considered
 *    to be constructed.
 */

/*
 * Detacting and handling invalid arguments to constructor.
 *
 * There could be possibilities of passing invalid arguments(invalid data type)
 * to the constructor.
 * But, here we dont have very much things to do. If we conditionally change the
 * value then its against the requirement of the user.
 * So, we set the value as per the user requirement and then try to overcome
 * the errors.
 *
 * Also, we can place the assert and static_assert inside the constructor body
 * to detect the errors.
 *
 * Also we know if we have errors inside function body we can do:
 * 1. Resolve the error inside the function body.
 * 2. Pass the error back to the caller to deal with it.
 * 3. Halt the program.
 * 4. Throw an exception.
 *
 * In most cases constructor dont have enough information to resolve the issue.
 * Also function returns nothing so we cannot return back the error. But also
 * we can add isValid() member function which we can set to represent if object
 * is in valid state or not.
 * Halting the programming and reruning is also not a proper solution.
 *
 * Then we have only one option "Exceptions". Exceptions abort construction
 * process completely, due to which user dosent get the access to the semantically
 * invalid object.
 */

class Student
{
    private:
        std::string m_name {};
        int m_age {};

    public:
        Student (std::string name, int age)
            : m_name(name), m_age(age)  // This is out member initialization list
        {
            std::cout << "Student(" << m_name << ", " << m_age
                <<") constriuctor is called!" << std::endl;
        }
};

int main()
{
    Student student1 {"Shubham", 10};
    return 0;
}
