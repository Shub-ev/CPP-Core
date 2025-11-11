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
 *
 */
class Fruit
{
    public:
        enum Type {
            apple,
            banana,
            mango,
        };

    private:
        Type my_type {};
        int m_eatPercent {0};

    public:
        Fruit(Type type)
            :my_type(type)
        {}

        Type getType() { return my_type; }
        int getEatPercent(){ return m_eatPercent; }
};

int main()
{
    Fruit fruit1 { Fruit::banana };
    std::cout << fruit1.getType() << std::endl;
    return 0;
}
