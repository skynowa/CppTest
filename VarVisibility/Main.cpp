 /*
 * \file  main.cpp
 * \brief var visibility
 */


//-------------------------------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
//-------------------------------------------------------------------------------------------------
class A
{
public:
    const int i;

    A() :
        i(1)
    {
    }

    void print()
    {
        std::cout << "i = "       << i       << std::endl;

        const int i = 2;

        std::cout << "this->i = " << this->i << std::endl;
        std::cout << "i = "       << i       << std::endl;
    }
};
//-------------------------------------------------------------------------------------------------
int main(int argsNum, char **args)
{
    A a;
    a.print();

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

i = 1
this->i = 1
i = 2

#endif
