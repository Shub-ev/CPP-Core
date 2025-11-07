#include <iostream>

/*
 * Access specifiers
 *
 * Members of the class type have the property called "access level", that
 * determines who can access that member.
 *
 * C++ have 3 different access levels:
 * 1. Private
 * 2. Protected
 * 4. Public
 *
 * Whenever a member is accessed compiler checks the access level of the member
 * permits the member to be accessed.
 * If access is not permitted then compiler will genarate compiletime error.
 *
 * This access level system is sometimes informally called as "access controls"
 */

/*
 * Public
 *
 * 1. Members of the struct are public by default.
 * 2. Public members of the class type are the members who do not have any
 *    restriction on how they can be accessed.
 * 3. Public members can be accessed by the other members of the same class.
 * 4. Public members also can be accessed by the "public" (code outside the
 *    members of a given class type).
 */

struct Student {
    /*
     * Here name and age are public members.
     * 1. These can be accessed by other members of same class type.
     *    (Here print() can directly access the public members of implicit
     *     object).
     * 2. In main() we can directly access the public members.
     *    (student.name;)
     * 3. Also we can directly access the public member functions. Because
     *    main is not member of student it is considered as public.
     */
    std::string name {};
    int age;

    void print()
    {
        std::cout << "Name : " << name << "\nAge: " << age << std::endl;
    }
};

/*
 * Private
 *
 * 1. Members of the class are private by default.
 * 2. Private members are the members those can be accessed by the other
 *    members of the same class "only".
 * 3. It is common convention to name private data members stating with an
 *    "m_" prefix.
 *    This is helpful to differentiate function parameters and actual object
 *    members.
 *    Similarly, "s_" for local static and "g_" for globals.
 *    If we have function parameter as the same name as of class member, then
 *    function parameter will shadow the member.
 */

// We cannot have class with same name if we have any other structure with
// that name.
class Teacher {
    /*
     * Here,
     * name, age and print() members are private, Hence outer world (public)
     * cannot access these members directly.
     * But print() is the member of this class type and members can access
     * other private members hence print() member function can access and
     * perform operations on these private members.
     */
    std::string name {};
    int age;

    void print()
    {
        std::cout << "Name : " << name << "\nAge: " << age << std::endl;
    }
};

/*
 * Access specifiers.
 *
 * We can explicitly set the acccess levels of members using access specifiers.
 * An access specifiers set the access levels of all the members that follow
 * the specifier.
 * C++ provides access specifiers: Public, Protected, Private.
 */
class Employee {
    /*
     * Here,
     * We are using private access specifier over data members.
     * And using public access specifier over member function.
     *
     * Since, classes default to private so private: is not required.
     */
    private:
        std::string name {};
        int age {};

    public:
        void print()
        {
            std::cout << "Name: " << name << "\nAge: " << age << std::endl;
        }
};

/*
 * Best practices:
 *
 * 1. struct should avoid access specifiers all together. Because we want our
 *    structs to be aggregates. Using public: is redundant for struct.
 * 2. classes have public member functions to provide the behaviour to outside
 *    world and keep the data members private.
 */

/*
 * Difference between struct and class is:
 *
 * 1. Struct have default access specifier as "public" and class have default
 *    access specifier as "private".
 * 2. struct inherits from other class types publically and classes inherits
 *    from other types privately.
 */

/*
 * Use Struct when:
 * 1. Have simple collection of data that dosent benefit from restricting
 *    access.
 * 2. Aggregate initialization is sufficient.
 * 3. You have no class invariants.
 */

int main()
{
    Student student1 {"Shubham", 21};
    student1.name = "Harish";   // public access of member name
    student1.age++;             // public access of member age
    student1.print();           // access public member function

    /*
     * We cannot use aggregate initialization because we have private
     * members.
     * An aggregate can have "no private or protected non-static data members".
     *
     * -> Teacher teacher1 {"Girish", 20}; This is now allowed now.
     */
    // teacher1.name = "Ganu";  // compile-time error
    // error: std::string Teacher::name is private within this context
    // teacher1.print();        // compile-time error
    // error: 'void Teacher::print()' is private within this context 

    // As we have private members we cannot perform aggregate initialization
    Employee emp1;
    emp1.print();               // this works because print() is public.
    return 0;
}
