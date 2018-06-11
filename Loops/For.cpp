 /*
 * \file  Main.cpp
 * \brief 
 */


//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
//---------------------------------------------------------------------------
bool
trace(const std::string &csPoint) {
    std::cout << csPoint;

    return true;
}
//---------------------------------------------------------------------------
int main(int, char **)
{
    int g = 0;
    for (trace("1"); trace("2"); trace("3")) {
        std::cout << " [block]" << std::endl;

        ++ g;
        if (5 == g) break;
    }

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

12 [block]
32 [block]
32 [block]
32 [block]
32 [block]

#endif