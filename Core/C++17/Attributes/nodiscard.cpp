/**
 * \file  main.cpp
 * \brief [[nodiscard]]
 *
 * This attribute is used to indicate that the return value of the function should not be ignored:
 * [[nodiscard]] can be also applied to data types or enumerations to mark all functions that
 * return this type as [[nodiscard]]:
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
[[nodiscard]] int Sum(int a, int b)
{
    return a + b;
}

struct [[nodiscard]] NoDiscardType
{
    char a;
    int b;
};

NoDiscardType Func()
{
    return {'a', 42};
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    Sum(5, 6); // Compiler/analyzer warning will be issued

    Func(); // Compiler/analyzer warning will be issued

    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
