/**
 * \file  BinaryData.cpp
 * \brief std::string can hold binary data. That is, a string with '\0' in any position.
 *        Note that it’s not entirely trivial to create such a string
 *
 * \see   https://shaharmike.com/cpp/std-string/
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    // For example, the following will create a string with the content "hello" by-design,
	// as we’re passing in a C-string:
	{
		std::string str = "aaa\0bbb";

		std::cout << STD_PRINT_VAR(str) << ", " << STD_PRINT_VAR(str.size()) << std::endl;
	}

	// Even doing something like the following will fail for the exact same reason:
	{
		auto cstr = "aaa\0bbb";
		std::string str(cstr, strlen(cstr));

		std::cout << STD_PRINT_VAR(str) << ", " << STD_PRINT_VAR(str.size()) << std::endl;
	}

	// The following, however, will work:
	// We could use const char[] or decltype(auto) here, but not auto. Why?
	// Because auto will be decayed to const char*, which has the wrong size.
	{
		decltype(auto) cstr = "aaa\0bbb";
		std::string str(cstr, sizeof(cstr));

		std::cout << STD_PRINT_VAR(str) << ", " << STD_PRINT_VAR(str.size()) << std::endl;
	}

	// Also note that printing such strings may also be problematic,
	// as some implementations stop at '\0'

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

str: [aaa],    str.size(): [3]
str: [aaa],    str.size(): [3]
str: [aaabbb], str.size(): [8]

#endif
