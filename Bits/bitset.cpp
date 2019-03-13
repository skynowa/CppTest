/**
 * \file  bitset.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <bitset>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	{
		std::bitset<4> b(std::string("1010"));

		std::cout << TRACE_VAR(b) << std::endl;

		for (size_t i = 0; i < b.size(); ++ i) {
			std::cout << TRACE_VAR(b[i]) << std::endl;
		}

		std::cout << std::endl;
	}

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

b: 1010
b[i]: 0
b[i]: 1
b[i]: 0
b[i]: 1

#endif

