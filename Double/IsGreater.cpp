/**
 * \file  main.cpp
 * \brief
 *
 * Returns whether x is greater than y.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	{
		const double d    {0.000000001};
		const double test {0.0};

		const bool bRv = std::isgreater(d, test);

    	std::cout << TRACE_VAR3(d, test, bRv) << std::endl;
	}

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
