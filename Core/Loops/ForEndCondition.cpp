/**
 * \file  ForEndCondition.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//---------------------------------------------------------------------------
int main(int, char **)
{
	const std::size_t value_max {1};

	for (size_t i = 0; i < value_max; ++ i) {
		std::cout << TRACE_VAR2(value_max, i) << std::endl;
	}

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

value_max: 1, i: 0

#endif