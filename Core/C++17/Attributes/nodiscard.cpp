/**
 * \file  nodiscard.cpp
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
[[nodiscard]] int
Sum(int a, int b)
{
    return a + b;
}
//-------------------------------------------------------------------------------------------------
struct [[nodiscard]] NoDiscardType
{
    char a;
    int b;
};
//-------------------------------------------------------------------------------------------------
NoDiscardType Func()
{
    return {'a', 42};
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    // Compiler/analyzer warning will be issued
    Sum(5, 6);

    // Compiler/analyzer warning will be issued
    Func();

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

warning: ignoring return value of ‘int Sum(int, int)’, declared with attribute nodiscard [-Wunused-result]
warning: ignoring returned value of type ‘NoDiscardType’, declared with attribute nodiscard [-Wunused-result]

#endif
