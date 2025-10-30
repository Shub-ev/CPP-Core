#include <iostream>
#include <utility>

/*
 * Class Template
 *
 * struct Pair {
 *      int a;
 *      int b;
 * };
 *
 * struct Pair {
 *      double a;
 *      double b;
 * };
 *
 * This is invalid and will generate errors because we cannot
 * overload program-types as function or operators.
 * To avoid this we have to create class-Templates.
 *
 * A class-type is a struct, class or union type.
 */
template <typename T>
struct Pair {
    T first {};
    T second {};
};

/*
 * Now we can use these class template into function parameters
 * to overload the function.
 */

template <typename T>
T max (const Pair<T>& pair)
{
    return (pair.first > pair.second) ? pair.first : pair.second;
}

int main()
{
    Pair<int> pair1 {1, 2};         // instantiates pair of int
    std::cout << pair1.first << " " << pair1.second << std::endl;
    /*
     * Once this code is compiled based on our code,
     * like, Pair<int> pair1 {1 ,2};
     * is compiled into.
     *
     * template<>
     * struct Pair<int>
     * {
     *      int first {};
     *      int second {};
     * };
     *
     * and similar for other types if we have instantiated.
     */
    Pair<float> pair2 {1.5f, 2.4f}; // instantiates pair of float
    std::cout << pair2.first << " " << pair2.second << std::endl;

    Pair<double> pair3 {2.4, 4.5};  // instantiates pair of double
    std::cout << pair3.first << " " << pair3.second << std::endl;

    std::cout << "Max1 : " << max(pair1) << std::endl;
    std::cout << "Max2 : " << max(pair2) << std::endl;

    /*
     * As using pairs is very common C++ Standard Library contains
     * a class template named std::pair (in the <utility> header).
     */
    std::pair<int, int> pr {1,3};

    return 0;
}
