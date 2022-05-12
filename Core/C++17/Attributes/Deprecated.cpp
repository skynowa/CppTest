/**
 * \file  Deprecated.cpp
 * \brief
 *
 * Indicates that the use of the name or entity declared with this attribute is allowed,
 * but discouraged for some reason. Compilers typically issue warnings on such uses.
 * The string-literal, if specified, is usually included in the warnings.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
 //-------------------------------------------------------------------------------------------------
[[deprecated]]
void
foo1()
{
    STD_TRACE_FUNC
}
 //-------------------------------------------------------------------------------------------------
[[deprecated("Use foo22() instead")]]
void
foo2()
{
    STD_TRACE_FUNC
}
//-------------------------------------------------------------------------------------------------
class A
{
public:
    static void foo3();
};

[[deprecated("Use foo33() instead")]]
void
A::foo3()
{
    STD_TRACE_FUNC
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    // foo1();
    // foo2();
    // A::foo3();

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

// warnings

#endif
