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

	x.has_value() // == true

	std::any_cast<int>(x) // == 5
	std::any_cast<int&>(x) = 10;
	std::any_cast<int>(x) // == 10

    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
