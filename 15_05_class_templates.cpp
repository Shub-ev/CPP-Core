#include <iostream>

/*
 * Class templates with member functions.
 *
 * We have already studied, how to define "function templates" and along with
 * that how to define "type template parameters".
 */
template <typename T>
class Pair
{
    /*
     * In scope of the class, the unqualified name of the class is called an
     * "injected class name".
     * In a class template, the injected class name serves as shorthand for the
     * fully templated name. Because Pair is the injected name of Pair<T>.
     */
    private:
        T m_x {};
        T m_y {};

    public:
        // When we define member function inside the class definition,
        // the template parameter declaration belonging to the class applies
        Pair(T x, T y):
            m_x(x), m_y(y)
        {}

        bool isEqual(const Pair<T>& pair);
};
// When we define member function outside the class definition,
// we need to resupply a template parameter declaration.
//
// Any member function templates defined outside the class definition should be
// defined just below the class definition (in the same file).
template <typename T>
bool Pair::isEqual(const Pair<T>& pair)
{
    return m_x == pair.m_x && m_y == pair.m_y;
}

int main()
{
    return 0;
}
