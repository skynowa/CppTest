/**
 * \file  MethodWithoutBody.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
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
    STD_UNUSED(a);

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
