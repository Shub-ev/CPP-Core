#include <iostream>

/*
 * Temporary Class Object
 *
 * Here, below we are returning variable by value.
 */
int add1(int a, int b) {
    int sum { a + b };
    return sum;
}

/*
 * But also if we have only one variable and expression to perform, we can
 * return that expression instead of using variable.
 */
int add2(int a, int b) {
    return { a + b };
}

void printValue(int val)
{
    std::cout << val << std::endl;
}

// Here function expects lvalue and not rvalue.
// So, we cannot call like addOne({ 3 + 4 }) this is not an lvalue
void addOne(int& value){
    ++value;
}

/*
 * Temporary class object.
 *
 * The same issue applies in the context of class type object.
 */
class Pair
{
    private:
        int m_x {};
        int m_y {};

    public:
        Pair(int x, int y)
            : m_x(x), m_y(y)
        {}

        int x() { return m_x; }
        int y() { return m_y; }
};

// This function expects lvale and rvalue both so expression and actual
// value both can be used. While calling this function we dont have to create
// separate object.
void print(Pair p) {
    std::cout << "(" << p.x() << ", " << p.y() << ")\n";
}

int main()
{
    /*
     * Same way we can use this for function arguments.
     * This way we dont have to define extra variable.
     *
     * Note: this will work in cases where rvalues are accepted but will generate
     *       compilertime error, if we provice rvalue to lvalue expecting parameter.
     */
    printValue({ 5 + 4 });

    /*
     * here while calling print with Pair object we can pass "temporary object".
     * also called as "unnamed object" or "anonymous object".
     * Object that has no name and exsist only for that expression.
     *
     * There are two ways to create temporary class object.
     */
    // 1. Here we tell compiler to construct a Pair object, and initialize it
    //    with { 1, 2 }, becaues this object dont have any name it is temp.
    //    Then this temp object is passed to the function and when function
    //    returns object is destroyed.
    print(Pair {1, 2});

    // 2. This also create temporary object, but here we havent explicitly
    //    specified what type to construct, the compiler will deduce the necessary
    //    type from the function parameter, and then implicitly convert {1, 2}
    //    to a Pair object.
    print({ 1, 2 });
    print(Pair(1,2)); // This is also valid
    return 0;
}
