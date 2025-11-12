#include <iostream>

/*
 * Nested types (member types)
 *
 * So, far we have seen classes with 2 types of members.
 * 1. Data members.
 * 2. Member functions.
 *
 * class types also support another type of member
 * 3. member type / nested type
 *
 * To declare nested type we just need to define any type under the appropriate
 * access specifier.
 *
 * 1. Nested types should be defined at the start of the class, so all member
 *    have access to it.
 * 2. Nested types follow normal access rules.
 * 3. Class types acts as the scope region for names declared within, just as
 *    namespaces do. So we can access Type as Fruit::Type
 * 4. Within members of the class we dont need to use fully qualified name.
 *    Outside the class we should use fully qualified name.
 */

/*
 * Nested typedefs and type alias.
 *
 * Class types can contain nested typedefs or type alias.
 */
class Fruit
{
    public:
        enum Type {
            apple,
            banana,
            mango,
        };

        // This is type alias and we can use this directly as Number.
        // But, outside this we need to specify fully qualified name as
        // Fruit::Number.
        using Number = int;

    private:
        Type my_type {};
        Number m_eatPercent {0};

    public:
        Fruit(Type type)
            :my_type(type)
        {}

        Type getType() { return my_type; }
        Number getEatPercent(){ return m_eatPercent; }
};

/*
 * Nested classes and access to outer class members.
 *
 * It is possible for classes to have class as a nested type.
 * 1. A nested class dont have access to the "this" pointer of the outer class.
 * 2. So nested classes dont have direct access to the members of the outer
 *    class.
 * 3. This is because nested class can be instantiated independantly of the
 *    outer class and in such cases there will be no outer class members to
 *    access.
 * 4. As nested class are the members of the inner class they can have access
 *    to private members of the outer class.
 * 5. Nested types can be forward declared within the class that encloses it.
 *    The nested type can be defined letter, either within the enclosing class
 *    or outside of it.
 *
 * There are not very common scenarios where we use nested classes but one
 * is as "iterators" for containers. Like std::string::iterator is implemented
 * as a nested class of std::string.
 */
// 6. We can not forward declare inner class outside (before defining) the
// enclosing class.
class Employee {
    public:
        class Printer {
            public:
                void printEmployee(const Employee& e) const
                {
                    /*
                    * Printer cannot access Employee's 'this' pointer
                    * so we can't print m_name and m_id directly
                    * Instead, we have to pass in an Employee object to use.
                    * As Printer is a member of Employee we can access private
                    * members of Employee.
                    */
                    std::cout << e.m_name << " has id: " << e.m_id << std::endl;
                }
        };

    private:
        std::string m_name {};
        int m_id {};

    public:
        Employee(std::string name, int id):
            m_name(name), m_id(id)
        {}
};

int main()
{
    Fruit fruit1 { Fruit::banana };
    std::cout << fruit1.getType() << std::endl;

    // Using typedef from Fruit class, we need to specify fully qualified name.
    Fruit::Number num {10};

    const Employee emp1 {"Shubham", 21};
    const Employee::Printer prt1 {};
    prt1.printEmployee(emp1);

    return 0;
}
