 /*
 * \file  main.cpp
 * \brief
 */


//-------------------------------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
//-------------------------------------------------------------------------------------------------
class A
{
public:
    void foo();
};
//-------------------------------------------------------------------------------------------------
int main(int argsNum, char **args)
{
    A a;

    std::cout << "Begin" << std::endl;
    // a.foo();
    std::cout << "End" << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

    Begin
    End

#endif

