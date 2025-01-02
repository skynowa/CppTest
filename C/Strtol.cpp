/**
 * \file  Strtol.cpp
 * \brief Convert "string" values to long int
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// Strings
	{
		std::cout << "Strings:" << std::endl;

	    const std::vector<std::string> values
		{
			// Strings
			"true",
			"TRUE",
			"false",
			"FALSE",
			"xxxxxx",
			"NULL",
			"nullptr",
			""
		};

		for (const auto &it_value : values) {
			const long int liRv = std::strtol(it_value.c_str(), nullptr, 10);
			std::cout << STD_TRACE_VAR(it_value) << " -> " << liRv << std::endl;
		}

		std::cout << std::endl;
	}

	// Digits
	{
		std::cout << "Digits:" << std::endl;

	    const std::vector<std::string> values
		{
			"1",
			"2",
			"+1",
			"+2",
			"-1",
			"-2",
			"0",
			"-0"
		};

		for (const auto &it_value : values) {
			const long int liRv = std::strtol(it_value.c_str(), nullptr, 10);
			std::cout << STD_TRACE_VAR(it_value) << " -> " << liRv << std::endl;
		}
	}

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Strings:
it_value: true    -> 0
it_value: TRUE    -> 0
it_value: false   -> 0
it_value: FALSE   -> 0
it_value: xxxxxx  -> 0
it_value: NULL    -> 0
it_value: nullptr -> 0
it_value:         -> 0

Digits:
it_value: 1  -> 1
it_value: 2  -> 2
it_value: +1 -> 1
it_value: +2 -> 2
it_value: -1 -> -1
it_value: -2 -> -2
it_value: 0  -> 0
it_value: -0 -> 0

#endif
