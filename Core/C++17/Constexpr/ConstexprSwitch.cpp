/**
 * \file  ConstexprSwitch.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
constexpr int
foo(int i)
{
	switch(i) {
	case 0:
		return 7;
	default:
		return 5;
    }
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	int var = foo(3);

    std::cout << TRACE_VAR(var) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

var: 5

#endif
