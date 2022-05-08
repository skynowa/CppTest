/**
 * \file
 * \brief
 *
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>

#include <limits>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::cout << TRACE_VAR(std::numeric_limits<float>::min()) << std::endl;
	std::cout << TRACE_VAR(std::numeric_limits<float>::max()) << std::endl;
	std::cout << TRACE_VAR(std::numeric_limits<float>::infinity()) << std::endl;

	float dRv = strtod("2037362412.80", nullptr);

    std::cout << TRACE_VAR(dRv) << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

std::numeric_limits<float>::min(): 1.17549e-38
std::numeric_limits<float>::max(): 3.40282e+38
std::numeric_limits<float>::infinity(): inf
dRv: 2.03736e+09

#endif
