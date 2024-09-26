/**
 * \file  FunctionDefinition.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class A
{
public:
    // called
    explicit A()
    {
        std::cout << "A - ctor" << std::endl;
    }

    // NOT called
    void operator () ()
    {
        std::cout << "A - operator()" << std::endl;
    }
};
//-------------------------------------------------------------------------------------------------
// NOT called
A a()
{
    std::cout << "A - function" << std::endl;

    return A{};
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    {
        A a;
    }

    {
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wvexing-parse"

        // function definition (not constructor, not operator())
        A a();

    #pragma GCC diagnostic pop
    }

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

error: empty parentheses were disambiguated as a function declaration [-Werror=vexing-parse]

A - ctor

#endif
