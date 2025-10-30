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

/*
 * Here, we will discuss about the owner members and viewer members
 * of struct.
 * In most cases we want out struct to be the owner of tha data they cotain.
 * If struct have member that is just viewer then is that data is freed or
 * removed we will end up with dangling member.
 */
struct Str_own {
    std::string str_o {};
};

struct Str_view {
    std::string_view str_v {};
};

std::string get_string()
{
    return std::string {"Hello"};
}

int main()
{
    /*
     * Example,
     * We will create Str_own struct variable which holds the actual data.
     * when get_string() return string, that temporary variable is copied into
     * our new variable and will be deleted at the end of called expression.
     *
     * As now out Str_own struct variable owns the data, so even if get_string()
     * temp-obj is deleted still we have the data.
     */
    Str_own str_own {get_string()};
    std::cout<<str_own.str_o<<std::endl;

    /*
     * Example,
     * We will crete Str_view variable and which will hold the view-reference of
     * temp-obj. As when caller expression ends temp-obj is destroyed and we dont
     * have any view reference to it.
     */
    Str_view str_view {get_string()};
    std::cout<<str_view.str_v<<std::endl;

    return 0;
}
