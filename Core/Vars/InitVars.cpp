/**
 * \file  InitVars.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
struct Point
{
	signed char  x;
	unsigned int y;

	void print() const
	{
	    std::cout << STD_TRACE_VAR2(x, y) << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	{
		Point p;
		p.print();
	}

	{
		Point p {};
		p.print();
	}

	{
		Point p = {126, 40};
		p.print();
	}

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

x: <UB>,  y: <UB>
x: <NUL>; y: 0
x: ~;     y: 40

#endif
