/**
 * \file  BracedInitList.cpp
 * \brief New rules for auto deduction from braced-init-list
 *
 * Changes to auto deduction when used with the uniform initialization syntax.
 * Previously, auto x {3}; deduces a std::initializer_list<int>, which now deduces to int.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// error: not a single element
	{
		/// auto x1 {1, 2, 3};
	}

	// decltype(x2) is std::initializer_list<int>
	{
		auto x2 = {1, 2, 3};
		std::cout << TRACE_VAR(x2.size()) << std::endl;
	}

	// decltype(x3) is int
	{
		auto x3 {3};
		std::cout << TRACE_VAR(x3) << std::endl;
	}

	// decltype(x4) is double
	{
		auto x4 {3.0};
		std::cout << TRACE_VAR(x4) << std::endl;
	}

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

x2.size(): 3
x3: 3
x4: 3

#endif
