/**
 * \file  Casts.cpp
 * \brief
 */


#include <StdTest.h>

//-------------------------------------------------------------------------------------------------
int main(int argsNum, char **args)
{
    int try_avail = 78.4;

    double drv1 = try_avail         + 0.001;
    double drv2 = (double)try_avail + 0.001;

    std::cout << drv1 << std::endl;
    std::cout << drv2 << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

78.001
78.001

#endif


