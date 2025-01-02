/**
 * \file  CStrData.cpp
 * \brief .c_str() and .data() are the same
 *
 * \see   https://shaharmike.com/cpp/std-string/
 *
 * Calling .data() in C++98 would not necessarily return a null-terminated string.
 * C++11 changes this and now both data() and c_str() return a string that must terminate with a '\0'.
 *
 * Another thing C++11 brings is the ability to dereference the pointer returned from
 * c_str() / data() even if empty() == true.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// No longer is it undefined to do.
	// As now c_str() / data() will return a pointer to '\0'

	// Not empty
	{
		const std::string str("test");
		std::cout << STD_PRINT_VAR(str) << std::endl;

		for (const char *c = str.data(); *c != 0; ++ c) {
			std::cout << '\t' << STD_TRACE_VAR(c) << std::endl;
		}

		std::cout << "\n" << std::endl;
	}

	// Empty
	{
		const std::string str;
		std::cout << STD_PRINT_VAR(str) << std::endl;

		for (const char *c = str.data(); *c != 0; ++ c) {
			std::cout << '\t' << STD_TRACE_VAR(c) << std::endl;
		}

		std::cout << std::endl;
	}

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

str: [test]
	c: test
	c: est
	c: st
	c: t


str: []

#endif
