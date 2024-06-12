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

    std::string s {"Hello"};

    X() = default;

    X(const int a_value) :
        a{a_value}
    {
    }
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    {
        X x;

        std::cout << STD_TRACE_VAR3(x.a, x.b, x.s) << std::endl;
    }

    {
        X x(10);

        std::cout << STD_TRACE_VAR3(x.a, x.b, x.s) << std::endl;
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

x.a: -1286932424, x.b: 32766, x.s: Hello
x.a: 10,          x.b: 32766, x.s: Hello

#endif
