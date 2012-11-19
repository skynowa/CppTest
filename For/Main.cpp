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
int main(int iArgCount, char **paszArgs)
{
    int i = 0;
    for (
        trace("1"); 
        trace("2"); 
        trace("3\n")
    )
    {
        ++ i;
        if (i == 5) break;
    }

    // 

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT
// NOTE:

123
23
23
23
2

#endif