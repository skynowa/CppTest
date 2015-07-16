/**
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
    A()
    {
        std::cout << "A - class" << std::endl;
    }

    A operator () ()
    {
        std::cout << "A - operator()" << std::endl;
    }
};
//-------------------------------------------------------------------------------------------------
int main(int argsNum, char **args)
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

    A - class

#endif