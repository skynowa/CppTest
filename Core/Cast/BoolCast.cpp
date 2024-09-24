/**
 * \file  BoolCast.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// int
	{
		std::cout << std::boolalpha << STD_TRACE_VAR(static_cast<bool>(-10)) << std::endl;
		std::cout << std::boolalpha << STD_TRACE_VAR(static_cast<bool>(-0)) << std::endl;
		std::cout << std::boolalpha << STD_TRACE_VAR(static_cast<bool>(0)) << std::endl;
		std::cout << std::boolalpha << STD_TRACE_VAR(static_cast<bool>(20)) << std::endl;
		std::cout << std::endl;
	}

	// double
	{
		std::cout << std::boolalpha << STD_TRACE_VAR(static_cast<bool>(-10.0)) << std::endl;
		std::cout << std::boolalpha << STD_TRACE_VAR(static_cast<bool>(-0.0)) << std::endl;
		std::cout << std::boolalpha << STD_TRACE_VAR(static_cast<bool>(-0.01)) << std::endl;
		std::cout << std::boolalpha << STD_TRACE_VAR(static_cast<bool>(0.0)) << std::endl;
		std::cout << std::boolalpha << STD_TRACE_VAR(static_cast<bool>(0.001)) << std::endl;
		std::cout << std::boolalpha << STD_TRACE_VAR(static_cast<bool>(20.0)) << std::endl;
		std::cout << std::endl;
	}

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

static_cast<bool>(-10): true
static_cast<bool>(-0): false
static_cast<bool>(0): false
static_cast<bool>(20): true

static_cast<bool>(-10.0): true
static_cast<bool>(-0.0): false
static_cast<bool>(-0.01): true
static_cast<bool>(0.0): false
static_cast<bool>(0.001): true
static_cast<bool>(20.0): true

#endif
