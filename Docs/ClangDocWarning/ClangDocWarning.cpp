/**
 * \file  ClangDocWarning.cpp
 * \brief Clang - warn about incorrect Doxygen documentation
 *
 * \see   Build.sh - for Clang build with `-Wdocumentation` flag
 */


#include <iostream>
//--------------------------------------------------------------------------------------------------
/**
 * Add two integers.
 *
 * \param  a The first integer.
 * \param  b The second integer.
 * \return The sum of the two integers.
 */
int add(int a, int b)
{
    return a + b;
}
//--------------------------------------------------------------------------------------------------
/**
 * Subtract two integers.
 *
 * \param  a The first integer.
 * \param  wrong_param_name The second integer (Incorrect parameter name here).
 * \return The difference of the two integers.
 */
int subtract(int a, int b)
{
    return a - b;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::cout << add(5, 3) << std::endl;
    std::cout << subtract(5, 3) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

ClangDocWarning.cpp:31:12: warning: parameter 'wrong_param_name' not found in the function declaration [-Wdocumentation]
 * \param  wrong_param_name The second integer (Incorrect parameter name here).
           ^~~~~~~~~~~~~~~~
ClangDocWarning.cpp:31:12: note: did you mean 'b'?
 * \param  wrong_param_name The second integer (Incorrect parameter name here).
           ^~~~~~~~~~~~~~~~
           b
1 warning generated.

#endif
