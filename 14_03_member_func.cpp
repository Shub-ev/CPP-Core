#include <iostream>

/*
 * Member function
 *
 * Struct can have member variables as shown below.
 * Now, if we want to print this function we need to create another function
 * then pass the instance of this struct to the function.
 *
 * But in real world properties(attributes) and behaviours are inseparable.
 * In addition to member variables class types (struct, class, union) can have
 * functions as their own members.
 * Functions belongs to a class type are called "member functions". In other
 * OOP languages these are called as "methods".
 *
 * Functions those are not member functions are called "non-member functions"
 * or "free functions". print() function is a free-function.
 *
 * 1. Member function must be declared inside the class-type definition, but
 *    definition of member function can be either inside or outside of class
 *    type definition.
 *
 * 2. Member functions declared inside the class type are implicitly inline, so
 *    they will not cause the violatoin of the one-definition rule if the class
 *    type definition is included into multiple files.
 *
 * 3. We select the member function using member selection operator (.). All
 *    member function must be called using an object of that class-type.
 *
 * 4. In case of member function we dont need to explicitly pass the object as
 *    an argument. The object of which member function is called, is implicitly
 *    passed to the member function. Hence, the object that a member function
 *    is called on is called the "implicit object".
 *    ex. date.printDate(); here date is implicit object, and it is implicitly
 *    passed to the printDate() member function.
 *
 * 5. As out member function have received implicitly passed object, we dont
 *    need to member access operator. We can directly access the values as,
 *    day;     date.day; is implicit
 *    month;   date.month; is implicit
 *
 * In the code below if we had separate printDate() function then that would be
 * in the global namespace, and by default that would have external linkage.
 */
struct Date {
    int day {};
    int month {};
    int year {};

    // This is a member function
    void printDate()
    {
        std::cout << "Date: " << day << "/" << month << "/"
                  << year << std::endl;
    }
};

struct Person {
    std::string name {};
    int age {};

    int getAge();   // member function declaration

    /*
     * Here we one implicitly passed object and one object is explicitly
     * passed. Here people is explicitly passed.
     * Hence, we have to write people.name to access its members.
     * But, we can use name of implicitly passed member directly.
     */
    void sayHi(const Person& people)
    {
        std::cout << name << "said hi! to " << people.name << std::endl;
    }
};
// This is how we can provide member function definition outside of
// our class type.
int Person::getAge() { return age; }

/*
 * 1. Non-members (functions / attributes) must be declared before use. To
 *    avoid this, use forward declaration so compiler will know about the
 *    non-member before the use.
 *
 * 2. But, inside class definition we can define members and attributes in
 *    any order. Also we can access any member before it has been declared.
 *
 * 3. But we cannot use data members which are not yet declared to initialize
 *    another members. This results in undefined behaviour.
 *
 * 4. To allow declaration of data members in any order, compiler forward
 *    declares the member function when ever it encounter one and function
 *    definition is moved to the end of the class.
 *
 * 5. Members functions can be overloaded as long as functions can be
 *    differentiated.
 *
 * 6. class-types with constructors are no longer aggrigates. Hence we should
 *    avoid defining struct constructors as we want struct to be aggrigates.
 *
 * 7. It is possible to create class-types with no data members
 *    (member functions only). But if class type dont have any data members
 *    then defining it as class type is overkill. Define member functions
 *    inside a namespace.
 */

// Class type with no members
struct Temp1 {
} temp1;

// declaring functions into namespace
namespace Temp {
    int getValue() { return 10; }
}

struct Stroo {
    int z() { return my_data; }

    int a {b};
    int b = 10;

    private:
        int my_data;

    // There is one recommended order of such declaration. refer 14.8
};

int main()
{
    Date date1 {10, 10, 2024};  // aggregate initialize the sturct.
    date1.printDate();

    // use function from namespace
    std::cout << Temp::getValue() << std::endl;

    return 0;
}
