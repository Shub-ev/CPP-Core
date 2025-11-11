#include <iostream>

/*
 * this Pointer
 *
 * When we call member function of any object how c++ compiler knows about the
 * object and its state.
 * -> C++ utilizes a hidden pointer named "this".
 *
 * Inside every member function, the keyword this is a constant pointer that
 * holds the address of the current implicit object.
 */

class Student {
    std::string m_name {};
    int m_age {};

    public:
        void setName(std::string name) { m_name = name; }
        void setAge(int age) { m_age = age; }

        /*
         * There print is a member function of Student and hence it has
         * implicit access to the object.
         *
         * Even if we dont write this->m_name,compiler will automatically
         * appent this-> as prefix.
         *
         * As, caller is changed(read notes where we are calling this) function
         * signature also needs to be changed.
         * New function signature will be:
         * static void print(Student* const this);
         * 1. Now our leftmost parameter is const pointer to the object.
         *    Whenever compiler rewrites our function it adds the const address
         *    parameter the "left most".
         * 2. Also, the function is "static" because now the function is not
         *    associated with any object the reason is we have passed object
         *    pointer explicitly.
         * 3. Almost all the member functions are updated like this and are
         *    converted to the static.
         * 4. Exception is static member function. As they are associated with
         *    whole class and not a specific instance. They do not operate on
         *    specific object. Hence, they do not receive implicit this pointer
         */
        void print()
        {
            std::cout << "Student: " << this->m_name << std::endl;
        }
};

/*
 * When to use this:
 * 1. Every time we calling a non-static member function, no need to explicitly
 *    specify this->. Even if not specifited compiler will add this prefix.
 * 2. But, also we need to use this-> if the function parameter is same is our
 *    data-member. We use this-> with out data-member.
 * 3. It is preferred to use m_data_member along with function parameters, and
 *    avoid using this-> as it reduces the readability of the code.
 */

/*
 * We can also return this*, a reference to the implicit object. The primary
 * reason is to allow member functions to be "chained" together, so several
 * member function can be called on the same object in a single expression.
 * This is called "function chaining" or "method chaining".
 */
class Calculator {
    int m_result {};

    public:
        Calculator& add(int value) { m_result += value; return *this; }
        Calculator& sub(int value) { m_result -= value; return *this; }
        Calculator& mul(int value) { m_result *= value; return *this; }

        void print() { std::cout << m_result << std::endl; }
};

/*
 * Resetting Class back to Default
 *
 * Constructors are just for initialization of new objects, and should not be
 * called directly. Doing so will result in unexpected behaviour.
 *
 * Best way to reset object back to default state is to create a reset()
 * function, have that function create new object (using default constructor)
 * and then assign that new object to the currect implicit object.
 */
int main()
{
    Student student1;
    student1.setName("Shubham");

    /*
     * Here, even there's no parameter passed by the programmer. But when
     * compiled it will be like,
     * student1.print(&student1);
     */
    student1.print();

    Calculator cal1;
    cal1.print();

    /*
     * Here we are using method chaining.
     * As member function returns the reference of implicit object, we can chain
     * this reference to the next function.
     *
     * Here below,
     * 1. cal1.add(20) is called with 20, this returns the reference to
     *    *this, which is the reference to the implicit object cal1.
     * 2. So we can all next member function on that reference of implicit
     *    object.
     * 3. As this always points to the implicit object we dont need to check for
     *    whether it is null pointer before dereferencing.
     */
    cal1.add(20).sub(10).mul(5);
    cal1.print();

    void reset()
    {
        this* = {};  // value initialize a new object and overwrite the implicit
    }
    return 0;
}

/*
 * For non-constant member function, "this" is a const pointer to a non-constant
 * value. meaning this cannot be pointed at something else.
 */

/*
 * Why this is a pointer and not a reference.
 *
 * "this" is a pointer and not a reference. And the answer is when "this" was
 * added references didnt exist. but languages like C++, like java and C#
 * this is reference.
 */
