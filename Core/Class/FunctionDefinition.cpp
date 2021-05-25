/**
 * \file  FunctionDefinition.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class A
{
public:
    explicit A()
    {
        std::cout << "A - ctor" << std::endl;
    }

    void operator () ()
    {
        std::cout << "A - operator()" << std::endl;
    }
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    {
        A a;
    }

    {
        // function definition (not constructor, not operator() )
        A a();
    }

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

A - ctor

#endif
