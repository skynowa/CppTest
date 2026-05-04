/**
 * \file  Kiss.cpp
 * \brief keep it simple stupid
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
bool isEven(int a_value)
{
	return a_value % 2 == 0;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	for (const int value : {1, 2, 3, 4}) {
		std::cout << STD_TRACE_VAR(value) << ", " << STD_TRACE_VAR(isEven(value)) << std::endl;
	}

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

value: 1, isEven(value): 0
value: 2, isEven(value): 1
value: 3, isEven(value): 0
value: 4, isEven(value): 1

#endif
