#include <iostream>

/*
 * Delegating Constructors
 *
 * Whenever possible we want to reduce redundant code. (DRY- dont repeat yourself)
 * Constructors also can be redundant or some parts of them can be.
 */
class Student{
    private:
        std::string m_name {};
        int m_age {};
        bool m_is_monitor {};

    public:
        // These constructors are the example of redundant code.
        Student(std::string name, int age)
            : m_name(name), m_age(age)
        {
            // std::cout << "Student: " << m_name << " created!" << std::endl;
            printCreated();
        }
        Student(std::string name, int age, bool is_monitor)
            : m_name(name), m_age(age), m_is_monitor(is_monitor)
        {
            // std::cout << "Student: " << m_name << " created!" << std::endl;
            printCreated();
        }

        // Here, we have created helper function to reduce the redundant code.
        void printCreated()
        {
            std::cout << "Student: " << m_name << " created!" << std::endl;
        }
};

/*
 * This code is better as we have reduced redundant statements and created one
 * new helper function, but again we are calling that helper function is redundant.
 *
 * Its not good idea to print something inside constructors body.
 * except debugging logs.
 */


/*
 * This also will not work correctly.
 * Because, first 2nd constructor will be called and it has only one data member
 * inside initializers list. And once list is executed we are calling another
 * constructor to initialize name and id.
 *
 * But, object initialization completes when initializer list is completed.
 * Hence calling another constructor from function body will create temporary
 * object unnamed object and direct-initialize it.
 *
 * Hence, constructors should not be called from the body of another function.
 */
class Employee
{
private:
    std::string m_name { "???" };
    int m_id { 0 };
    bool m_isManager { false };

public:
    Employee(std::string_view name, int id)
        : m_name{ name }, m_id { id } // this constructor initializes name and id
    {
        std::cout << "Employee " << m_name << " created\n";
        // our print statement is back here
    }

    Employee(std::string_view name, int id, bool isManager)
        : m_isManager { isManager } // this constructor initializes m_isManager
    {
        // Call Employee(std::string_view, int) to initialize m_name and m_id
        Employee(name, id); // this doesn't work as expected!
    }

    const std::string& getName() const { return m_name; }
};

/*
 * Delegating constructors.
 *
 * constructors are allowed to delegate (transfer the responsibility for) initialization
 * to another constructors from the same class type.
 *
 * This process is sometimes called "constructor chaining" and such constructors
 * are called "delegating constructors".
 *
 * -> To make one constructor delegate initialization to another constructor, simply
 *    call the constructor in the member initializer list.
 *
 * Rules:
 * 1. Constructor that delegates to another constructor is not allowed to do any
 *    member initialization itself.
 * 2. Usually, we delegate from constructor with less parameters to the constructor
 *    with more parameters. If we do opposite we will endup with useless members.
 * 3. It is also possible for one construtor to delegate to another which
 *    delegates back to the caller constructor, in this way this creates an
 *    infinite loop and stack space will be exausted.
 */

class Employee1{
    private:
        std::string m_name {};
        int m_id {};

    public:
        // Here we are delegating the control from this constructor to the another
        // constructor.
        Employee1(std::string name)
            : Employee1{name, 0}
        {}

        // First body of the delegated constructor will be executed then body of
        // the calling constructor will be called. Finally control returns to
        // the caller.
        Employee1(std::string name, int id)
            : m_name(name), m_id(id)
        {
            std::cout << "Employee " << m_name <<" created!" << std::endl;
        }
};

/*
 * We can also reduce constructors using default arguments.
 * We can also write above code using default arguments as below.
 */
class Employee2
{
    private:
        std::string m_name {};
        int m_id;

    public:
        /*
         * Here, instead of delegating from one constructor to another
         * we are just using default arguments so it will work with different
         * number of arguments.
         *
         * Note: Default arguments should be on the right most part.
         */
        Employee2(std::string name, default int id = 0)
            :m_name(name), m_id(id)
        {
            std::cout << "Employee " << m_name << " created!\n";
        }
}

/*
 * Disadvantage of these methods is:
 * 1. Duplicate data members values.

int main()
{
    Student student1 {"Shubham", 12};
    Student student2 {"Hari", 14, true};

    Employee1 employee1{"Shubham", 12};
    Employee1 employee2{"Hari", 32};
    return 0;
}
