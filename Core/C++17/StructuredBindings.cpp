/**
 * \file  main.cpp
 * \brief Structured bindings
 *
 * A proposal for de-structuring initialization, that would allow writing auto [ x, y, z ] = expr;
 * where the type of expr was a tuple-like object, whose elements would be bound
 * to the variables x, y, and z (which this construct declares). Tuple-like objects
 * include std::tuple, std::pair, std::array, and aggregate structures.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
using Coordinate = std::pair<int, int>;

Coordinate origin()
{
	return Coordinate {7, 13};
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const auto &[ x, y ] = origin();

	// x: == 0
	// y: == 0

    std::cout << TRACE_VAR(x) << std::endl;
    std::cout << TRACE_VAR(y) << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
