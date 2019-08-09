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
	{
		const auto &[ x, y ] = origin();

		// x: == 0
		// y: == 0

	    std::cout << TRACE_VAR(x) << std::endl;
	    std::cout << TRACE_VAR(y) << std::endl;

		std::cout << std::endl;
	}

	{
		std::map<int, char> myMap {{1, 'a'}, {2, 'b'}};

		for (const auto &[key, value] : myMap) {
			std::cout << TRACE_VAR2(key, value) << std::endl;
		}
	}

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

x: 7
y: 13

key: 1, value: a
key: 2, value: b


#endif
