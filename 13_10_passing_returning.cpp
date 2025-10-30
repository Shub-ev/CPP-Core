#include <iostream>

struct Student {
    std::string name;
    int age;
};

/*
 * This function accept struct and prints it.
 * Advantage of struct:
 * 1. We dont have to pass multiple parameters to function.
 * 2. In future is we add members, we dont have to change function proto.
 *
 * Here, we are passng it as constant reference. (PoLP)
 */
void print_struct(const Student& student)
{
    std::cout << "Student: " << student.name << "\nAge: "
        << student.age << std::endl;
}

/* Overload above function with non-const reference parameters
 * to check if temporary objects can be accepted by non-const
 * reference variables.
 *
 * (
 *  Not possible because tem-obj is rvalue expression and hence it will
 *  only bind to parameters that accept rvalue.
 *  1. Pass by value.
 *  2. pass by const reference.
 *
 *  Do not support:
 *  3. pass by non-const reference.
 *  4. pass by address.
 * )
 */

void print_struct(Student& student)
{
    std::cout << "Student: " << student.name << "\nAge: "
        << student.age << std::endl;
}

/*
 * We can return struct from function as:
 * 1. Return by Value.
 * 2. Return pointer to struct.
 * 3. Return temporary object.
 */
Student getStudent()
{
    /* As we have expicit return type no need to provide Student while creating
     * temporary object.
     * => return Student {"Madhav Patil", 24};      // This is return temp-obj
     * This object will be copied to called and will be destroyed.
     */
    return {"Madhav Patil", 24};                    // Is also correct
}

int main()
{
    Student student1 {"Shubham Gharage", 10};
    print_struct(student1);

    /*
     * If we are using struct variable only once then creating dedicated object
     * can increase complexity, instead we can use "temporary structs".
     * temporary is not an object so it does not have an idenifier.
     *
     * Important:
     * 1. Temporary objects are created and initialized at the time of def.
     * 2. Destroyed at the end of full expression in which they are created.
     * 3. Evaluation of a temporary object is an rvalue expression.
     */
    print_struct(Student {"Hari Gopal", 21});   // Preferred
    print_struct({"Ganesh Gharage", 20});       // Also valid
    return 0;
}
