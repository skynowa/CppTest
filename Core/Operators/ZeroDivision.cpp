/**
 * \file  ZeroDivision.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const long val = 12;
	const auto rv  = val % 0;

    std::cout << TRACE_VAR(rv) << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

Floating point exception (core dumped)

#endif
