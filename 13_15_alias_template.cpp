#include <iostream>

/*
 * Type alias let us to define alias for an existing type.
 * We can also create type alias for class-templates.
 */

template <typename T>
struct Pair {
    T first {};
    T second {};
};

template <typename T>
T max(const Pair<T>& pair)
{
    return (pair.first > pair.second) ? pair.first : pair.second;
}

/*
 * We can have type-alias for template class.
 * To do this, we define alias template.
 *
 */
template <typename T>
struct Game {
    std::string name;
    int price;
};
// This is out alias template.
// Alias template must be defined in global scope
template <typename T>
using Crood = Game<T>;              // Crood is alias for Game<T>

// our print_game function must know Crood's template parameter T is
// a type template parameter.
template <typename T>
void print_game(const Crood<T>& crood)
{
    std::cout<< "Game: " << crood.name << "\nPrice: " << crood.price;
}

int main()
{
    // Creating type-alias for class Template
    using Point = Pair<int>;
    Point p {1, 2};                 // compiler replaces this with Pair<int>

    Crood<int> crood1 {1, 2};       // pre C++20: we must specify all type
                                    // template arguments

    Crood crood2 {1, 2};            // In C++20: we can use alias template
                                    // deduction to deduce the template args.

    return 0;
}
