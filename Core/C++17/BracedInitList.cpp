/**
 * \file  main.cpp
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
	/// auto x1   {1, 2, 3}; // error: not a single element
	auto x2 = {1, 2, 3}; // decltype(x2) is std::initializer_list<int>
	auto x3   {3};       // decltype(x3) is int
	auto x4   {3.0};     // decltype(x4) is double

    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
