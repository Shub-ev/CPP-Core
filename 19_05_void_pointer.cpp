#include <iostream>

/*
 * Void Pointer.
 *
 * void pointer is also know as "generic pointer".
 * Is a special type of pointer that can point to objects of any type.
 * void pointer is declared like normal pointer.
 *
 * As void pointer doesnt know what type of object it is pointing dereferencing
 * void pointer is illegal.
 * Void pointer first cast to some another pointer then should be dereferenced.
 *
 * We can set void pointer to nullptr as:
 * void* ptr {nullptr};
 *
 * But we cannot delete void pointer as other pointers, and will result in
 * undefined behaviour. First we need to cast void pointer to appropriate type.
 * We cannot perform pointer arithmatic on void pointer.
 */

int main()
{
    int a {10};
    float f {1.4};

    void *ptr1 {};      // ptr1 is a void pointer.
    ptr1 = &a;
    ptr1 = &f;

    // std::cout << *ptr1 << std::endl;    // this is illegal
    std::cout << *(static_cast<float*> (ptr1))<< std::endl;

    return 0;
}
