/**
 * \file  CtorDefaultInitMembers.cpp
 * \brief Init members with default values
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class X
{
public:
    int a;
    int b;

    // Compile error
    // const int &c;

    X() = default;
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    X x;

    std::cout << STD_TRACE_VAR2(x.a, x.b) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

x.a: 0, x.b: 0

#endif
