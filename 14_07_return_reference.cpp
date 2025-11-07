#include <iostream>

/*
 * Member function returning Reference to data members.
 * 1. We should not return reference to the local variables as reference will
 *    be left dangling after the local variable is destroyed.
 * 2. It is okay to return by reference either function parameters passed by
 *    reference or variables with static duration.
 * 3. Returning data members by value can be expensive.
 */
const std::string& compareStr(const std::string& a, const std::string& b)
{
    // We can use operator< on string to determine which comes first alphabetically.
    return (a < b) ? a : b;
}

/*
 * Returning data members by lvalue reference.
 *
 * 1. Data members has the same life as the object containing them.
 * 2. As member functions are always called on the objects containing them, that
 *    objects must exist in the scope of caller, it is mostly safe to return data
 *    members by const references.
 * 3. In general, return type of a member function returning by reference should
 *    match the data member being returned.
 * 4. Using "auto" reference return type is also good, but increases unnecessary
 *    complexity so use explicit return types.
 */
class Student {
    std::string m_name {};

    public:
        void setName(std::string_view name) { m_name = name; }
        const std::string& getName() { return m_name; }
        void print() { std::cout << m_name << std::endl; }
};

/*
 * Rvalue and return by reference
 *
 * Sometimes, return reference of rvalue returned by another function can also
 * result in undefined behaviour, as rvalues have life till the completion of
 * expression.
 * And when rvalue is destroyed we end up with danglign reference.
 */
// This function returns Student by value i.e. rvalue
Student createStudent(std::string_view name)
{
    Student student;
    student.setName(name);
    return student;
}

int main()
{
    Student student1;
    student1.setName("Shubham");
    student1.print();

    /*
     * createStudent() returns Student by value which is a rvalue, henec it will
     * be alive till the end of expression.
     */
    const std::string& ref1 { createStudent("Shubham").getName() };
    std::cout << ref1 << std::endl;

    return 0;
}
