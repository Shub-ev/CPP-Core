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
