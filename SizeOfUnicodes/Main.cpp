 /*
 * \file  Main.cpp
 * \brief 
 */


//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
#include <tchar.h>
//---------------------------------------------------------------------------
int main(int iArgCount, char **paszArgs)
{
    std::cout << "sizeof(_T('|0')) = " << sizeof(_T('\0')) << std::endl;
    std::cout << "sizeof(_T('0'))  = " << sizeof(_T('0'))  << std::endl;

#if xNOT_COMPILED || ! UNICODE
    std::cout << "sizeof(_T(0))    = " << sizeof(_T(0))    << std::endl;
#endif

    std::cout << "sizeof(0)        = " << sizeof(0)        << std::endl;

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

// Ansi
    sizeof(_T('|0')) = 1
    sizeof(_T('0'))  = 1
    sizeof(_T(0))    = 4
    sizeof(0)        = 4

// Unicode
    sizeof(_T('|0')) = 2
    sizeof(_T('0'))  = 2
    sizeof(_T(0))    = // not compiled
    sizeof(0)        = 4

#endif