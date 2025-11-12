#include <iostream>

/*
 * Exceptions, classes, and inheritance
 */

/*
 * 1. Exceptions and member functions
 *
 * you’ve only seen exceptions used in non-member functions. However, exceptions
 * are equally useful in member functions, and even more so in overloaded
 * operators.
 * 
 * Consider the following overloaded [] operator as part of a simple integer
 * array class:
 * 
 * int& IntArray::operator[](const int index)
 * {
 *      return m_data[index];
 * }
 * 
 * Although this function will work great as long as index is a valid array index,
 * this function is sorely lacking in some good error checking. We could add an
 * assert statement to ensure the index is valid
 */

int main()
{
    return 0;
}