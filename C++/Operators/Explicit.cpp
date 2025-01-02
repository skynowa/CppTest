/**
 * \file  Explicit.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
struct A
{
	operator bool() const
	{
		return true;
	}
};

struct B
{
	explicit operator bool() const
	{
		return true;
	}
};

struct C
{
	explicit operator bool() const
	{
		return true;
	}
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	A a;
	std::cout << STD_TRACE_VAR(a) << std::endl;

	B b;
	STD_UNUSED(b);
	// std::cout << STD_TRACE_VAR(b) << std::endl;

	C c;
	std::cout << STD_TRACE_VAR(static_cast<bool>(c)) << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

a: 1
no known conversion for argument 2 from 'B' to 'int'
static_cast<bool>(c): 1

#endif
