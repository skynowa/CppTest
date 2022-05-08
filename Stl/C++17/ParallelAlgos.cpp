/**
 * \file  main.cpp
 * \brief Parallel algorithms
 *
 * \todo
 *
 * Many of the STL algorithms, such as the copy, find and sort methods, started to support the
 * parallel execution policies: seq, par and par_unseq which translate to "sequentially",
 * "parallel" and "parallel unsequenced".
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
#if 0
	std::vector<int> longVector;

	// Find element using parallel execution policy
	auto result1 = std::find(std::execution::par, std::begin(longVector), std::end(longVector), 2);

	// Sort elements using sequential execution policy
	auto result2 = std::sort(std::execution::seq, std::begin(longVector), std::end(longVector));

    // std::cout << TRACE_VAR("") << std::endl;
#endif

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
