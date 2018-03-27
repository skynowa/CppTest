/**
 * \file  main.cpp
 * \brief
 */


#include <StdTest.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	size_t buffSize = 5;

	size_t buff[buffSize] {0, 1, 2, 3, 4};

    std::cout << STD_TRACE_VAR(buff[4]) << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

buff[4]: 4

#endif

