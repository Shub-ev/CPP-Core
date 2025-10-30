/*
 * Compile this code as:
 * -> g++ 001_scoped_enum.cpp -o main -std=c++23
 */

#include <iostream>
#include <utility> // For to_underlying();

enum class Color {
    red,
    white,
    green,
};

enum class Fruit {
    banana,
    apple,
};

int main()
{
    /*
     * As Color & Fruit are scoped nums we need scope resolutions
     * before using this enumerators.
     */
    Color color {Color::red};
    Fruit fruit {Fruit::banana};

    /*
     * We cannot compare scoped enumerators of different types
     * Hence, this will generate compiletime error.
     * -> if(color == fruit) {};
     */

    /*
     * But we can compare enumerators of same type.
     */
    if (color == Color::red) {};

    /*
     * Also we cannot cout<< scoped enumerators because numeric casting
     * is not allowed for scoped enumerators.
     * -> std::cout<<Color::red<<std::endl; // Compile-time error
     */

    // This is allowed.
    std::cout<<static_cast<int>(Color::red)<<std::endl;

    /*
     * Also we can use
     * -> to_underlying() to convert the enumerator to underlying type.
     * to_underlying() is present in <utility> header.
     */
    std::cout<<std::to_underlying(Color::white)<<std::endl;

    {
        /*
         * We can also do:
         * using enum
         * To import all the enumerators into the current scope.
         */
        using enum Color;

        if(red == color) {}; // This will work fine.
    }

    return 0;
}
