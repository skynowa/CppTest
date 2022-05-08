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
        // function definition (not constructor, not operator())
        A a();
    }

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

A - ctor


#endif
