#include <iostream>

/*
 * We will discuss about member slection of struct variable.
 * 1. If we have struct variable directly, then we can use
 *    member selection operator (.).
 * 2. Pointer to struct:
 *    a. Dereference the pointer then use member selection ope.
 *    b. Use arrow operator (->). (works same as member selection ope.
 *    but performs Dereferencing of struct pointer implicitly.)
 *
 * If we have type which hold both pointer members and normal
 * members then we have to use both (.) and (->) to access
 * the members.
 *
 * As (.) and (->) have same precedence, both are evaluate in
 * left to right order.
 */

struct Student {
    std::string name;
    int age;
};

/*
 * Reference of object acts like actual object hence we can
 * use (.) member selection operator on reference.
 */
void print_student (const Student& student)
{
    std::cout << "Student : " << student.name
        << "\nAge: " << student.age;
}

int main()
{
    Student joe {"Joe", 21};
    ++joe.age;                  // (.) have more precedence than ++

    print_student(joe);
    return 0;
}
