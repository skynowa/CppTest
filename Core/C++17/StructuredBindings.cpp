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
using Coordinate = std::pair<int, float>;

Coordinate origin()
{
	return Coordinate {7, 13.5};
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	{
		const auto &[x, y] = origin();

	    std::cout << TRACE_VAR2(x, y) << "\n" << std::endl;
	}

	{
		std::map<int, char> m {{1, 'a'}, {2, 'b'}};

		for (const auto &[key, value] : m) {
			std::cout << TRACE_VAR2(key, value) << std::endl;
		}
	}

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

x: 7, y: 13.5

key: 1, value: a
key: 2, value: b

#endif
