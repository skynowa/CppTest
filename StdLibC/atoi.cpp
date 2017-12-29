 /*
 * \file  main.cpp
 * \brief
 */


//---------------------------------------------------------------------------
#include <StdTest.h>

#include <iostream>
#include <stdlib.h>
#include <assert.h>
//---------------------------------------------------------------------------
int main(int iArgCount, char **paszArgs)
{
    std::string s;

    int a = ::atoi( s.c_str() );
    std::cout << STD_TRACE_VAR(a) << std::endl;

    int b = ::atoi("");
    std::cout << STD_TRACE_VAR(b) << std::endl;

    int c = ::atoi("NULL");
    std::cout << STD_TRACE_VAR(c) << std::endl;

#if 1
    int d = ::atoi(NULL);
    std::cout << d << std::endl;
#endif

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

a: 0
b: 0
c: 0
Segmentation fault

#endif
