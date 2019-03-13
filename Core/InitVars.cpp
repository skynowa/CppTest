/**
 * \file  main.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>

//-------------------------------------------------------------------------------------------------
struct Point
{
	signed char  x;
	unsigned int y;

	void print() const
	{
	    std::cout << TRACE_VAR2(x, y) << std::endl;
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

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

x: <UB>,  y: <UB>
x: <NUL>; y: 0
x: ~;     y: 40

#endif
