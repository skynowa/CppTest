/**
 * \file  IsAlpha.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const char str[] = "йцуке";

	for (const auto it_char : str) {
		int iRv = std::isalpha(it_char);
		if (iRv)
			printf ("std::isalpha: %ld - TRUE\n", (ssize_t)it_char);
		else
			printf ("std::isalpha: %ld - FALSE\n", (ssize_t)it_char);
	}

    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

std::isalpha: -48 - FALSE
std::isalpha: -71 - FALSE
std::isalpha: -47 - FALSE
std::isalpha: -122 - FALSE
std::isalpha: -47 - FALSE
std::isalpha: -125 - FALSE
std::isalpha: -48 - FALSE
std::isalpha: -70 - FALSE
std::isalpha: -48 - FALSE
std::isalpha: -75 - FALSE
std::isalpha: 0 - FALSE

#endif
