/**
 * \file  BoolCast.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// int
	{
		std::cout << TRACE_VAR(static_cast<bool>(-10)) << std::endl;
		std::cout << TRACE_VAR(static_cast<bool>(-0)) << std::endl;
		std::cout << TRACE_VAR(static_cast<bool>(0)) << std::endl;
		std::cout << TRACE_VAR(static_cast<bool>(20)) << std::endl;
		std::cout << std::endl;
	}

	// double
	{
		std::cout << TRACE_VAR(static_cast<bool>(-10.0)) << std::endl;
		std::cout << TRACE_VAR(static_cast<bool>(-0.0)) << std::endl;
		std::cout << TRACE_VAR(static_cast<bool>(-0.01)) << std::endl;
		std::cout << TRACE_VAR(static_cast<bool>(0.0)) << std::endl;
		std::cout << TRACE_VAR(static_cast<bool>(0.001)) << std::endl;
		std::cout << TRACE_VAR(static_cast<bool>(20.0)) << std::endl;
		std::cout << std::endl;
	}

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

static_cast<bool>(-10): 1
static_cast<bool>(-0): 0
static_cast<bool>(0): 0
static_cast<bool>(20): 1

static_cast<bool>(-10.0): 1
static_cast<bool>(-0.0): 0
static_cast<bool>(-0.01): 1
static_cast<bool>(0.0): 0
static_cast<bool>(0.001): 1
static_cast<bool>(20.0): 1

#endif
