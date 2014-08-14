 /*
 * \file  main.cpp
 * \brief compare doubles
 */


//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
//---------------------------------------------------------------------------
int main(int iArgCount, char **paszArgs)
{
    const double d = 0.0;

    if (d == 0.0) {
        std::cout << "d == 0.0" << std::endl;
    }

    if (d == 0) {
        std::cout << "d == 0" << std::endl;
    }

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

d == 0.0
d == 0

#endif
