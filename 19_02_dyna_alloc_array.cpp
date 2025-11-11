#include <iostream>

/*
 * Dynamically allocating Array
 *
 * Along with single variables we can dynamically allocate arrays of variables.
 *
 * Unlike a fixed array, where the array size must be fixed at the compile time
 * Dynamically allocated arrays allows us to chose the array length at runtime.
 *
 */

int main()
{
    std::cout << "Enter size of dynamic array: ";
    std::size_t length {};
    std::cin >> length;

    // As we are allocating array using int[], C++ know that is should use the
    // array version of new instead of scalar version of new.
    int *arr1 { new int[length] {} };   // Here we have allocated array of size
                                        // length dynamically.

    /*
     * Dynamically Deleting arrays.
     *
     * When deleting dynamically allocated array, we have to use the array ver.
     * of delete, which is "delete[]".
     * This tells the CPU that it needs to clean up multiple variables instead
     * of a single variable.
     * Note: using delete instead of delete[], means using scalar version of
     *       delete on an array will result in undefined behaviour.
     *
     * Important: How delete[] knows how much memory to delete. and the answer
     * is new[] keeps track of how much memory was allocated to a variable.
     * And this size is not accessible to the programmer.
     */
    delete[] arr1;

    /*
     * Initializing the dynamically allocated array.
     *
     * Now its possible to initialize dynamic arrays using "initializer list".\
     */
    int *arr2 { new int[length] {1, 2, 3, 4, 5, 6} };
    delete[] arr2;

    /*
     * Resizing arrays.
     *
     * C++, does not provide a build-in way to resize an array that has already
     * been allocated.
     * We can create new dynamically allocated array and copying the elements of
     * existing array into the new array.
     *
     * Instead, use vector<>
     */
    return 0;
}
