#include <iostream>

/*
 * Aggregate in C++:
 * Aggregate in C++ are either a C-style array or class type that has:
 * 1. No user-declared constructors
 * 2. No private or protected non-static data members
 * 3. No virtual functions
 * structs with only data members are aggregates.
 *
 * Normal variables can hold only one value so we need to provide only
 * one initializer. But struct have multiple members so we need a way
 * to initilize all.
 *
 * Aggregates use a form of initilization called "aggregate initilization",
 * we provide an initilizer list as an initializer.
 */

// Here members are uninitialized
struct Student {
    std::string name;
    int age;
};

struct Employee
{
    int id {}; // Value initialization
    int age;
    double wage { 76000.0 };
    double whatever;
};

/*
 * Overload << operator to print the structure.
 */
std::ostream& operator<<(std::ostream& os, const Employee& emp)
{
    return (
        os << "Employee : " << emp.id << "\nAge: " << emp.age
        << "\nWage: " << emp.wage
    );
}

int main()
{
    /*
     * We can do aggregate initilization by 2 ways:
     * 1. copy-list initialization.
     * 2. direct-list initialization.
     * 3. direct initialization.
     *
     * Here in list sequence of initializers should be same as members in type.
     * -> Prefer list-initialization (2).
     */
    Student jon = {"Jon Clint", 40};
    Student peter {"Peter Bottom", 23};
    Student ben {"Ben Parker", 10};

    // What if direct-list initialization have fewer values than struct members
    Employee emp {2};
    std::cout<<emp.id<<std::endl;               // initialized by {2}
    std::cout<<emp.age<<std::endl;              // value initialized to 0.0
    std::cout<<emp.wage<<std::endl;             // initialized by default member initializer
    std::cout<<emp.whatever<<std::endl;         // value initialized to 0.0

    Employee emp2;                              // not initialized
    std::cout<<emp2.id<<std::endl;              // Value initialization
    std::cout<<emp2.age<<std::endl;             // Garbage {undefined}
    std::cout<<emp2.wage<<std::endl;
    std::cout<<emp2.whatever<<std::endl;        // Garbage


    // print struct using overloaded << operator
    std::cout << emp << std::endl;
    std::cout << emp2 << std::endl;

    /*
     * Designated initializers
     * Allows explicitly define which initialization values map to which members.
     * Here also sequence in initialization list should be same as sequence of members.
     */
    Employee emp3 { .id{1234}, .wage{120000}};  // { .id{1234}, .age{0}, .wage{120000}, .whatever{0}}
    std::cout<<emp3<<std::endl;

    /*
     * Update emp3 members after initialization using initializers-list
     * We can do same thing using designated initializers
     */
    emp3 = {emp3.id, ++emp3.age, emp3.wage + 10000, emp3.whatever};
    std::cout<<emp3<<std::endl;

    /*
     * We can initialize structure with another structure of same type
     */
    Student jon1 = jon;                         // copy-initialization
    Student jon2 (jon);                         // direct-initialiaton
    Student jon3 {jon};                         // direct-list initialization

    return 0;
}
