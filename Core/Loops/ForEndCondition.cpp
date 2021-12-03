/**
 * \file  ForEndCondition.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//---------------------------------------------------------------------------
int main(int, char **)
{
	const std::size_t value_max {1};

	for (size_t i = 0; i < value_max; ++ i) {
		std::cout << TRACE_VAR(i) << std::endl;
	}

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

i: 0

#endif