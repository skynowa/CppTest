 /*
 * \file  main.cpp
 * \brief 
 */


//---------------------------------------------------------------------------
#include <iostream>
#include <stdlib.h>
#include <assert.h>
//---------------------------------------------------------------------------
int main(int iArgCount, char **paszArgs)
{
    std::string s;

    int a = ::atoi(s.c_str());
    std::cout << a << std::endl;  

    int b = ::atoi("");
    std::cout << b << std::endl;

    int c = ::atoi(NULL);
    std::cout << c << std::endl;

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

0
0
Segmentation fault

#endif
