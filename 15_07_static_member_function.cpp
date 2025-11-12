#include <iostream>

/*
 * Static member function
 *
 * Static data members are not bounded to and are independent of any object.
 * And these static data members can be accessed directly by their class name.
 * Student::Id;
 *
 * But what if static data member is private.
 * So to access private static data member we can create member function to get
 * the static data member, but again we have to create one instance of the class
 * then we should call the member function.
 *
 * Instead, we can make member functions static.
 *
 * 1. Static member function have no access to "this". As static member func.
 *    are not assiciated with any object.
 *
 * 2. Static member function can directly access other static members, but not
 *    non static members.
 *
 * Note: Member functions defined inside class definition are implicitly inline
 *       But member functions defined outside are note. But can be made using
 *       "inline" keyword.
 *
 * 3. Classes with all static members are called as "pure static class" or
 *    "monostates".
 *
 * 4. C++ dont have static constructors.
 */
class Student {
    private:
        std::string m_name;
        int m_id;
        inline static int stat_id {0};

    public:
        Student(std::string name):
            m_name(name), m_id(++stat_id)
        {
            std::cout << "Student: " << m_name << " (" << m_id << ")"
                << " created!" << std::endl;
        }

        void print()
        {
            std::cout << "Student: " << m_name << " (" << m_id << ")"
                << std::endl;
        }
        static int getStatId() { return stat_id; }
};

/*
 * Static member functions can also be defined outside of class declaration.
 * Same as normal member function.
 */
class Try {
    static inline int num {10};

    public:
        static int getNum();
};
// Here we are defining getNum() a static member function
// Here we are not using static keywork!
int Try::getNum() { return num; }

int main()
{
    Student student1 {"Shubham"};
    Student student2 {"Hari"};

    // We cannot access private static member here,
    // std::cout << Student::stat_id << std::endl;  // error: 'stat_id' is
                                                    // private withint this
                                                    // context

    // Here we are calling getStatId() static member function to retrive the
    // static variable value.
    std::cout << Student::getStatId() << std::endl;
    return 0;
}
