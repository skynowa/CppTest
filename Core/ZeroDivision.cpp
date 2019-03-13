/**
 * \file  main.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	long val = 12;
	auto rv = val % 0;

    std::cout << TRACE_VAR(rv) << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

Floating point exception

#endif

