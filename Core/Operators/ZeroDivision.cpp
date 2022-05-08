/**
 * \file  ZeroDivision.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const long val = 12;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdiv-by-zero"
	const auto rv  = val % 0;
#pragma GCC diagnostic pop

    std::cout << TRACE_VAR(rv) << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

Floating point exception (core dumped)

#endif
