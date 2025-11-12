#include <iostream>

/*** Rework Needed ***/

/*
 * Smart pointers and move semantics.
 *
 * We can use pointers to save the address of dynamically allocated memory.
 * But it is very common to forget to deallocate the memory. Even if we
 * remember still there are chances of functions exits early.
 *
 * Also we know that resources are allocated to the object through its
 * constructor and will be deallocated by the destructor. And destructor will
 * be called once object goes out of the scope. This is nothing but RAII 
 * (Resource Acquisition Is Initialization) principle.
 *
 * So, based on this we can create a class whose sole job is to hold the pointer
 * passed to it. And deallocate the memory pointed by the pointer once object
 * goes out of the scope. As long as object is local we can guarantee that
 * object will go out of scope.
 *
 * Such a class is called "Smart Pointer".
 * Relatively buildin pointers are called as "Dumb pointers".
 */
class Resource {
    std::string name;
    int number;

    public:
        Resource() { std::cout << "Resource Acquired!" << std::endl; }
        ~Resource() { std::cout << "Resource Deallocated!" << std::endl; }
};

template<typename T>
class Auto_ptr1
{
    T* m_ptr {};

    public:
        Auto_ptr1(T* ptr = nullptr):
            m_ptr(ptr)
        {}

        ~Auto_ptr1()
        {
            delete m_ptr;
        }

        // overload dereference and operator -> so we can use Auto_ptr1 list
        // m_ptr
        T& operator*() { return *m_ptr; }
        T* operator->() { return m_ptr; }
};

void ptrEx()
{
    // This is local pointer and cannot free memory automatically when function
    // exits early.
    Resource *ptr = new Resource();

    // Instead if we use smart pointer here to resolve the above issue.
    Auto_ptr1<Resource> res(new Resource());
    int x;
    std::cout << "Enter number: ";
    std::cin >> x;

    // This early exit dosent allow the function to free the dynamic memory
    // Also we dont have any other pointer to that memory after the function so
    // that will be the memory leak.
    if(x == 0)
        return;

    delete ptr;
}

int main()
{
    ptrEx();

    // Here we are creating new object of type Resource dynamically and passing
    // the pointer to the Auto_prt1 which will maintain it till its life span
    // and will deallocate the memory once destructor is called.
    Auto_ptr1<Resource> res(new Resource());

    /*
     * Heres, one issue
     *
     * what is we do,
     * Auto_ptr1<Resource> res1(res);
     *
     * Because now res1 have shallow copy of res, hence res and res1 are now
     * pointing to the same memory. Hence if any of these two objects call the
     * destructor memory will be deallocated. And if second object calls destr.
     * it will be called over invalid memory and will result in undefined beh.
     *
     * We can overcome this by explicitly defining and deleting copy constructor
     * and assignment operator, preventing any copies being made.
     */
    // Auto_ptr1<Resource> res1(res);
    return 0;
}
