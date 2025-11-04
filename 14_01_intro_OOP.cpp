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

#define 

int main()
{
    return 0;
}
