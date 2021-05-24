/**
 * \file  NamedParameterByThis.cpp
 * \brief Solve order of the parameters problem
 *
 * Change the function's parameters to methods of a newly created class, where all these methods
 * return *this by reference. Then you simply rename the main function into a parameterless "do-it"
 * method on that class
 *
 * When a function takes many parameters, the programmer has to remember the types and the order
 * in which to pass them. Also, default values can only be given to the last parameters,
 * so it is not possible to specify one of the later parameters and use the default value
 * for former ones. Named parameters let the programmer pass the parameters to a function in any
 * order and they are distinguished by a name. So the programmer can explicitly pass all the needed
 * parameters and default values without worrying about the order used in the function declaration.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class X
{
public:
	int  a {};
	char b {};

	X() :
		a{-999},
		b{'C'}
	{
	}

	// non-const function
	X &
	setA(const int i)
	{
		a = i;
		return *this;
	}

	// non-const function
	X &
	setB(const char c)
	{
		b = c;
		return *this;
	}

};
//-------------------------------------------------------------------------------------------------
std::ostream &
operator << (std::ostream &os, const X &x)
{
	os << TRACE_VAR2(x.a, x.b);

	return os;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	X x;
	x
		.setA(10)
		.setB('Z');

	std::cout << TRACE_VAR(x) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

x: x.a: 10, x.b: Z

#endif
