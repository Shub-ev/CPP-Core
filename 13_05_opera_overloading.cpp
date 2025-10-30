/*
 * Operator Overloading in CPP
 * Here we will try to overload '+' operator
 */


#include <iostream>
/*
 * In CPP Struct are very similar as Classes.
 * Except the difference in default access specifiers.
 */

struct Age {
    int age;

    Age(void) {
        age = 0;
    }

    Age(int age) {
        this->age = age;
    }
};

/*
 * Here we are using PoLP (Principle of Least Privilege)
 * Such that function/component/object should have only necessary privileges
 * to avoid accidental modifications.
 */
Age operator+ (const Age& a, const Age& b)
{
    return Age((a.age + b.age));
}

int main()
{
    // Create 2 Age objects.
    Age a = Age(5);
    Age b = Age(20);

    /*
     * We can't perform the addition of a + b as '+'
     * if operator is not yet overloaded.
     *
     * Here, '+' operator will first try to get any non-ambigious overloaded
     * operator+ method which matches with current expression.
     */
    Age c = a + b;

    std::cout<<"Age a: "<<a.age<<std::endl;
    std::cout<<"Age b: "<<b.age<<std::endl;
    std::cout<<"Age c: "<<c.age<<std::endl;

    return 0;
}
