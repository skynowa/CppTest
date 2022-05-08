/**
 * \file  IsAlpha.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const char str[] = "йцуке";

	for (const auto it_char : str) {
		int iRv = std::isalpha(it_char);

		printf ("std::isalpha: %ld - %d\n", (ssize_t)it_char, iRv);
	}

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

std::isalpha: -48  - 0
std::isalpha: -71  - 0
std::isalpha: -47  - 0
std::isalpha: -122 - 0
std::isalpha: -47  - 0
std::isalpha: -125 - 0
std::isalpha: -48  - 0
std::isalpha: -70  - 0
std::isalpha: -48  - 0
std::isalpha: -75  - 0
std::isalpha: 0    - 0

#endif
