/**
 * \file  MethodWithoutBody.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class A
{
public:
    void foo();
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    A a;

    std::cout << "Begin" << std::endl;
    // a.foo(); - undefined reference to `A::foo()'
    std::cout << "End" << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

Begin
End

#endif
