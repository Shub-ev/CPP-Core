#include <iostream>
// Imports the declaration of std::cout into global scope

/*
 * Name space:
 * 1. A namespace provides another type of scope region (called namespace scope)
 *    that allows you to declare or define names inside of it for the purpose
 *    of disambiguation.
 *
 * 2. A name declared within a scope region (such as a namespace) is distinct
 *    from any identical name declared in another scope.
 *
 * 3. Namespaces may only contain declarations and definitions
 *    (e.g. variables and functions). Executable statements are not allowed
 *    unless they are part of a definition (e.g. within a function).
 *
 * 4. any name that is not defined inside a class, function, or a namespace
 *    is considered to be part of an implicitly-defined namespace called the
 *    global namespace (sometimes also called the global scope).
 *
 * 5. When C++ was originally designed, all of the identifiers in the C++
 *    standard library (including std::cin and std::cout) were available to
 *    be used without the std:: prefix (they were part of the global namespace)
 *
 * 6. std::cout‘s name isn’t really std::cout. It’s actually just cout, and std
 *    is the name of the namespace that identifier cout is part of.
 *
 * 7. When an identifier includes a namespace prefix, the identifier is 
 *    called a "qualified name".
 */

// Global namespace/ global scope
int temp = 10;

/*
 * using-directive statement.
 * -> using namespace std;
 * A using directive allows us to access the names in a namespace without 
 * using a namespace prefix.
 *
 * This is bad practice because using-directive make all the names from
 * that namespace available to currect scope. This way there will be chances
 * of name-conflicts. Also if not now there could be conflicts due to
 * changes in language itself.
 */

int main()
{
    /*
     * Explicit namespace qualifier std::
     * std::cout means the cout is defined in the std namespace.
     * :: is "scope resolution operator".
     * operator to the left of :: is namespace and name is on right.
     * If no identifier is on left then global scope is assumed.
     */
    std::cout << ::temp << std::endl;
    return 0;
}
