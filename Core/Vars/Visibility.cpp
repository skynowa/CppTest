/**
 * \file  Visibility.cpp
 * \brief var visibility
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
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
int main(int, char **)
{
    A a;
    a.print();

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

i = 1
this->i = 1
i = 2

#endif
