/**
 * \file  main.cpp
 * \brief
 */


#include "../StdTest.h"

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	long val = 12;
	auto rv = val % 0;

    std::cout << STD_TRACE_VAR(rv) << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

Floating point exception

#endif
