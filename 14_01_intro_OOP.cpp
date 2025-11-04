#include <iostream>
#include <string_view>

/*
 * Object Oriented Programming (OOP)
 *
 * Object is "a piece of memory that can be used to store values."
 * Object with a name is called a variable.
 *
 * In procedural programming we write procedures (functions) that implement
 * out programming logic. Here function and data on which function performs
 * the operation are two different entities. Programmer is responsible to
 * combine the function and data to get desired results.
 *
 * But, in real world data (properties), and behaviours (their functions) are
 * single entity. Hence, procedural programming represent this poorly.
 *
 * In OOP, the focus is to create "program-defined" data types that contains
 * properties(attributes) and their behaviours in single entity. Term "object"
 * refers to the objects that we instantiate from such type.
 *
 * -> As properties and behaviours are no longer separate, this makes code more
 * modularize, easy to read and higher degree of reusability.
 */

#define PROCEDURAL_PROGRAMMING_EXAMPLE
#ifdef  PROCEDURAL_PROGRAMMING_EXAMPLE

/*
 * This is an example of procedural programming.
 * Here, if we want to change anything like add snake to AnimalType, we need to
 * change:
 * 1. AnimalType
 * 2. numLegs()
 * 3. animalName()
 */
enum AnimalType {
    cat,
    dog,
    chicken,
};

constexpr std::string_view animalName(AnimalType type)
{
    switch (type) {
        case cat: return "cat";
        case dog: return "dog";
        case chicken: return "chicken";
        default: return "";
    }
}

constexpr int numLegs(AnimalType type)
{
    switch (type) {
        case cat: return 4;
        case dog: return 4;
        case chicken: return 2;
        default: return 0;
    }
}
#endif

#define OOP_MINDSET_EXAMPLE
#ifdef OOP_MINDSET_EXAMPLE

/*
 * Here, we have program-defined type for each animal.
 * So, for each animal we just need to instantiate that type.
 * Also, if we want to add any animal we can just add that type.
 * Very less amount of code needs to be changed.
 */

struct Cat {
    std::string_view name {"cat"};
    int numLegs {4};
};

struct Dog {
    std::string_view name {"Dog"};
    int numLegs {4};
};

struct Chicken {
    std::string_view name {"Chicken"};
    int numLegs {2};
};

#endif

int main()
{
    return 0;
}
