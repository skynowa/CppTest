/**
 * \file  Atoi.cpp
 * \brief
 */

//---------------------------------------------------------------------------
#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>

#include <iostream>
#include <stdlib.h>
#include <assert.h>
//---------------------------------------------------------------------------
int main(int, char **)
{
    std::string s;

    int a = ::atoi( s.c_str() );
    std::cout << STD_TRACE_VAR(a) << std::endl;

    int b = ::atoi("");
    std::cout << STD_TRACE_VAR(b) << std::endl;

    int c = ::atoi("NULL");
    std::cout << STD_TRACE_VAR(c) << std::endl;

#if 0
	int d = ::atoi(nullptr);
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
