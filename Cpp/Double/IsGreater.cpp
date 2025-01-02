/**
 * \file  IsGreater.cpp
 * \brief Returns whether x is greater than y
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const double d    {0.000000001};
	const double test {0.0};

	const bool bRv = std::isgreater(d, test);
	std::cout << STD_TRACE_VAR3(d, test, bRv) << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

d: 1e-09, test: 0, bRv: 1

#endif
