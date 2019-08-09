/**
 * \file  main.cpp
 * \brief std::variant

 The class template std::variant represents a type-safe union. An instance of std::variant at any given time holds a value of one of its alternative types (it's also possible for it to be valueless).
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::variant<int, double> v{ 12 };
	std::get<int>(v); // == 12
	std::get<0>(v); // == 12
	v = 12.0;
	std::get<double>(v); // == 12.0
	std::get<1>(v); // == 12.0

    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
