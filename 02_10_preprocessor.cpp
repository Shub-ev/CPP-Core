#include <iostream>

/*
 * Pre-processing.
 * 1. Pre-processing takes place before compilation.
 *
 * 2. The preprocessor does not actually modify the original code files in 
 *    any way rather, all changes made by the preprocessor happen either 
 *    temporarily in-memory or using temporary files.
 *
 * 3. When the preprocessor has finished processing a code file, the result 
 *    is called a translation unit. This translation unit is then compiled by
 *    the compiler.
 *
 * 4. The entire process of preprocessing, compiling, and linking is called 
 *    translation.
 *
 * 5. During pre-processing phase, pre-processor search for pre-processor
 *    directives, are the instructions that start with a "#" symbol.
 *
 * 6. There pre-processors directives tells the preprocessor to perform
 *    some text manupilation tasks.
 */

/*
 * 1. #include
 * When we perform #include file then preprocessor replaces #include with
 * the contents of the file. Then included conents are preprocessod and this
 * takes place recursively until all #include s are processed.
 */

/*
 * 2. #define
 * Is used to create a macro, a macro is a rule that defines how input text
 * is converted into replacement output text.
 * There are two basic types of Macro:
 * 1. Object-like macros.
 * 2. Function-like macros.
 *

int main()
{
    return 0;
}
