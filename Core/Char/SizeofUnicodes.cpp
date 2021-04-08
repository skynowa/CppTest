/**
 * \file
 * \brief
 *
 * \todo
 */


//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
//---------------------------------------------------------------------------
int main(int, char **)
{
    std::cout << "sizeof(_T('|0')) = " << sizeof(L'\0') << std::endl;
    std::cout << "sizeof(_T('0'))  = " << sizeof(L'0')  << std::endl;
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
    sizeof(0)        = 4

#endif
