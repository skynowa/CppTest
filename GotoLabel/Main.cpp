 /*
 * \file  Main.cpp
 * \brief 
 */


//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
//---------------------------------------------------------------------------
int main(int iArgCount, char **paszArgs)
{
    // goto exit;

    std::cout << 1 << std::endl;;

    exit: {
        std::cout << 2 << std::endl;;
    }

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

// with goto
2

// with out goto
1 
2

#endif
