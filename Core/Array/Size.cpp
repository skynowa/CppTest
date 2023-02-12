/**
 * \file  Size.cpp
 * \brief Size of array
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const size_t buffSize {5};

	const size_t buff[buffSize] {0, 1, 2, 3, 4};

    std::cout << STD_TRACE_VAR(buff[4]) << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

buff[4]: 4

#endif
