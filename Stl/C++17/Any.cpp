/**
 * \file  main.cpp
 * \brief std::any
 *
 * A type-safe container for single values of any type.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::any x {5};

	std::cout << TRACE_VAR(x.has_value()) << std::endl; // == true

	std::cout << TRACE_VAR(std::any_cast<int>(x))  << std::endl; // == 5
	std::cout << TRACE_VAR(std::any_cast<int&>(x)) << std::endl; // == 10;
	std::cout << TRACE_VAR(std::any_cast<int>(x))  << std::endl; // == 10

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
