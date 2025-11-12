#include <iostream>

/**** Add more points from article 15.09 ****/

/*
 * Friend class and friend member functions.
 *
 * Friend class is a class that can access the private and protected members of
 * another class. Because the Display class is a friend of Storage, Display
 * members can access the private members of any Storage object they have
 * access to.
 *
 * 1. Even though Display is a friend of Storage, Display has no access to the
 *    *this pointer of Storage objects (because *this is actually a function
 *    parameter).
 *
 * 2. Friendship is not reciprocal. Just because Display is a friend of Storage
 *    does not mean Storage is also a friend of Display. If you want two classes
 *    to be friends of each other, both must declare the other as a friend.
 *
 * 3. A friend class declaration acts as a forward declaration for the class
 *    being friended. This means we do not need to forward declare the class
 *    being friended before friending it.
 */
class Storage
{
private:
    int m_nValue {};
    double m_dValue {};
public:
    Storage(int nValue, double dValue)
       : m_nValue { nValue }, m_dValue { dValue }
    { }

    // Make the Display class a friend of Storage
    friend class Display;
};

class Display
{
private:
    bool m_displayIntFirst {};
public:
    Display(bool displayIntFirst)
         : m_displayIntFirst { displayIntFirst }
    {
    }
    // Because Display is a friend of Storage, Display members can access the private members of Storage
    void displayStorage(const Storage& storage)
    {
        if (m_displayIntFirst)
            std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
        else // display double first
            std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
    }

    void setDisplayIntFirst(bool b)
    {
         m_displayIntFirst = b;
    }
};

/*
 * Friend member function.
 *
 * Instead of making an entire class a friend, you can make a single member
 * function a friend. This is done similarly to making a non-member function a
 * friend, except the name of the member function is used instead.
 *
 * In order to make a single member function a friend, the compiler has to have
 * seen the full definition for the class of the friend member function (not
 * just a forward declaration). Since class Storage hasn’t seen the full
 * definition for class Display yet, the compiler will error at the point where
 * we try to make the member function a friend.
 */
int main()
{
    Storage storage { 5, 6.7 };
    Display display { false };

    display.displayStorage(storage);

    display.setDisplayIntFirst(true);
    display.displayStorage(storage);

    return 0;
}
