#include <iostream>

/*
 * In C++, struct can have program-defined types as members.
 * There are 2 ways to do this:
 * 1. Declare one program-defined type globaly then use that type
 *    as member of another program-defined type.
 * 2. Nested types.
 */

// 1]
struct Employee {
    std::string name;
    int salary;
    int age;
};
struct Company {
    Employee *employees;
    Employee CEO {};
    int emp_cnt {};
};

// 2] Nested Types
struct School {
    struct Student {
        std::string name {};
        int age {};
        int std {};
    };

    Student *students;
};

int main()
{
    return 0;
}
