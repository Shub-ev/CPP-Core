#include <iostream>

/*
 * Frient non-member function.
 *
 * A friend function is a function (member or non-member) that can access the
 * private and protected members of a class as though it were a member of that
 * class.
 *
 */
class Student{
    private:
        std::string m_name;
        int m_age;

    public:
        Student(std::string name, int age):
            m_name(name), m_age(age)
        {}

        // Here, is the friend declaration that makes non-member function a
        // friend of Student.
        friend void printStudent(const Student& student);
};

/*
 * printStudent is non-member function and accept reference of student object,
 * hence it should now access the private and protected members of Student
 * object. But as we have declared this function as friend of Student type
 * it can access now.
 *
 * As printStudent is non-member of Student it will not receive "this" hence
 * we have to explicitly pass the reference of the object to the function.
 */
void printStudent(const Student& student)
{
    std::cout << "Student: " << student.m_name << " (" << student.m_age <<
        ")" << std::endl;
}

/*
 * We can define friend non member function inside the class type.
 * We are defining friend function inside class type dosent mean it is now a
 * member function.
 */
class Try {
    private:
        int m_num;

    public:
        explicit Try(int num):
            m_num(num)
        {}

        friend int getNumTry(const Try& try1) { return try1.m_num; }
};

/*
 * A function can be a friend of more than one class at the same time.
 * Consider the example below.
 * 1. As printWeather() is uses both Humidity and Temperature equally, it
 *    dosent really make sence to have it be a member of either.
 * 2. printWeather() is frient of both Temperature and Humidity hence it can
 *    access the private members of both class objects.
 * 3. class Humidity;
 *    is forward declaration.
 */
class Humidity;

class Temperature {
    private:
        int m_temp {};

    public:
        Temperature(int temp):
            m_temp(temp)
        {}

        friend void printWeather(const Temperature& temp, const Humidity& hum);
};

class Humidity
{
    private:
        int m_humi {};

    public:
        Humidity(int humi):
            m_humi(humi)
        {}

        friend void printWeather(const Temperature& temp, const Humidity& humi);
};

void printWeather(const Temperature& temp, const Humidity& humi)
{
    std::cout << "The temperature is " << temp.m_temp <<
        " and the humidity is " << humi.m_humi << '\n';
}

/*
 * Doesn’t friendship violate the principle of data hiding?
 *
 * No. Friendship is granted by the class doing the data hiding with the
 * expectation that the friend will access its private members. Think of a
 * friend as an extension of the class itself, with all the same access rights.
 * As such, access is expected, not a violation.
 *
 * We should avoid friend function if possible, as if we change anything inside
 * class type we need to change the friend function.
 */

int main()
{
    Student student1 {"Shubham", 21};
    printStudent(student1);

    Try try1 {10};
    std::cout << getNumTry(try1) << std::endl;

    Humidity hum { 10 };
    Temperature temp { 12 };

    printWeather(temp, hum);

    return 0;
}
