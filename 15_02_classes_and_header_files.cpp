#include <iostream>

/*
 * As classes get longer and more complicated, having all the member function
 * definitions inside the class can make the class harder to manage and work
 * with.
 *
 * Using an already written class only requires understaning its public
 * interface, not how the class works underneath the hood.
 *
 * member function implementations clutter up the public interface with details
 * that arent relevant.
 *
 * To overcome this issue we define the member functions outside the class def.
 * The only difference is while defining the function we should prefix the
 * function name with the name of the class type. e.g. Student:: so the compiler
 * will know were defining the member of that class type.
 * But prototype should still exist inside the class.
 */
class Student
{
    private:
        std::string m_name {};
        int m_age {};

    public:
        Student(std::string name, int age);
        void print() const;
        std::string getName() const { return m_name; }
        int getAge() const { return m_age; }
};
Student::Student(std::string name, int age)
    :m_name(name), m_age(age)
{
}
void Student::print() const
{
    std::cout << "Student(" << m_name << ", " << m_age << ")" << std::endl;
}

/*
 * Putting class definitions inside header files.
 * if we define class type inside .cpp source file then that class will be
 * available for that source file only. And its common that we'll want to use
 * the classes across multiple source files.
 *
 * Also, in header files we can write forward declarations of functions, this
 * cannot be done with classes. As while using any class type compiler should
 * know its all members to instantiate its object and allocate the memory.
 * Hence, mostly header files have complete definitions of class types.
 *
 * 1. Mostly classes are put into the header files with same name as of class.
 *    And any member function defined outside of the class are put in a a.cpp
 *    file of the same name as the class.
 */

int main()
{
    Student student1 {"Shubham", 21};
    student1.print();
    return 0;
}
