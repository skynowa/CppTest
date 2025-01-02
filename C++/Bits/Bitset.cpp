/**
 * \file  Bitset.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::bitset<4> b(std::string("1010"));

	std::cout << STD_TRACE_VAR(b) << std::endl;

	for (size_t i = 0; i < b.size(); ++ i) {
		std::cout << STD_TRACE_VAR(b[i]) << std::endl;
	}

	std::cout << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

b: 1010
b[i]: 0
b[i]: 1
b[i]: 0
b[i]: 1

#endif
