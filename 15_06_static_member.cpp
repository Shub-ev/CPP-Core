#include <iostream>

/*
 * Static member.
 *
 * Static variables (global and local) have static duration, means they are
 * created at the start of the program and will be destroyed at the end of the
 * program.
 *
 * Class members have 2 uses of static:
 * 1. static data members.
 * 2. static member functions.
 *
 */

/*
 * 1. Static data members.
 *
 * We have Num1 struct and if we instantiate it 2 times, we will get 2 diff
 * objects with theit own copy of num.
 * Member variables can be made static using "static" keyword. Unlike any
 * member variables static variables are shared by all the objects of the class
 *
 * Static members are not associated with class objects. We can access static
 * members with objects, static members exist even if no objects of the class
 * have been instantiated.
 * static members are global variables that live inside the scope of the class.
 *
 * Static data member exist independently hence we can directly access the
 * data member using scope resolution operator.
 *
 * 1. When we declare a static member inside a class type, we're telling the
 *    compiler about the existance of static member var. but not actually def.
 *    it. Because static member are essentially global variables, you must
 *    explicitly define (and optionally initialize) the static member outside
 *    of the class, in the global scope.
 *
 * 2. Static member may use auto to deduce its type from the initializer, or
 *    Class Template Arguments Deduction to deduce template type arguments.
 */
struct Num1 {
    int num {};
    static int stat_num;

    // static constant data members can be declared and initialized inside type
    // another good practice is, make static members inline or constexpr so they
    // can be initialized inside the class definition.
    static const int const_stat {10};
};
// Here we are defining static local variable for class type Num1, before
// defining here we need to define this in class type also (2 times 1 here and
// one in class type).
int Num1::stat_num = 0;

struct Num2 {
    // This is just declaration and no memory is allocated to this variable.
    // To allocate memory we must explicitly say
    // Num2::num = 10;
    static int num;
};
int Num2::num = 0;

int main()
{
    Num1 num1 {};
    Num1 num2 {};
    num2.num = 2;
    std::cout << num1.num << " " << num2.num << std::endl;

    Num2 num3 {};
    Num2 num4 {};
    std::cout << num3.num << " " << num4.num << std::endl;

    // And if we change static variable, change will reflec to all objects.
    num3.num++;
    std::cout << num3.num << " " << num4.num << std::endl;

    return 0;
}
