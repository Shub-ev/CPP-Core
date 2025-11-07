#include <iostream>

/*
 * Access Functions.
 *
 * In most of the classes data members are private, so user need a way to
 * access and modify the private data members.
 *
 * 1. "Access function" is a trivial public member function whose job is retrieve
 *    or change value of private data members.
 *    As member functions have direct access to the private members.
 *
 * 2. "Access functions" come in two flavors: "getters" and "setters".
 *    Getters: the member function that returns the value of private data member.
 *    Setters: the member function that sets the value of private data member.
 *
 * 3. "setters" are also known as "mutators". Mutator is any member function that
 *    changes the state of the object. Hence, setter is special type of mutator
 *    which updates the private data member.
 *
 * 4. Getters are usually made const, so they can be called on both const and
 *    non-const objects.
 *
 * 5. Setters should be non-const, so they can modify the data members.
 *
 * 6. There is no convention for access function naming. But few popular ways
 *    is to prefix getter function with "get" and prefix setter function with
 *    "set".
 *    Also, there is another way to declare getter and setters is using func.
 *    overloading:
 *    -> int day() const { return day; }
 *    -> void day(int day) { m_day = day; }
 *
 * 7. Getters should return by either "value" or by "const" lvalue reference.
 */

class Student {
    std::string m_name {};
    int m_age;

    public:
        void print()
        {
            std::cout << "Name: " << m_name << "\nAge: " << m_name << std::endl;
        }

        /*
         * Here, we will define getters and setters for our private data members.
         * Declaring getters with const qualifiers so they should work with
         * constant objects.
         */
        std::string getName() const
        {
            return m_name;
        }
        int getAge() const
        {
            return m_age;
        }

        void setName(std::string name)
        {
            m_name = name;
        }
        void setAge(int age)
        {
            m_age = age;
        }
};

int main()
{
    Student student {};
    // student.name;       // error: 'class Student' has no mamber named 'name'
    // Using setter to set the private data member.
    student.setName("Shubham");

    // using getName() getter to get the private data member.
    std::cout << "Name: " << student.getName() << std::endl;


    const Student student1 {};
    student1.getName();
    return 0;
}
