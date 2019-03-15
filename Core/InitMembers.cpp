/**
 * \file  main.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>

//-------------------------------------------------------------------------------------------------
struct Foo
{
	const int value {10};

	explicit Foo() :
		value(20)
	{
		std::cout << "Constructor: " << __FUNCTION__ << ", " << TRACE_VAR(value) << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
Foo foo()
{
	std::cout << "Along:       " << __FUNCTION__ << std::endl;

	return Foo();
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	Foo foo;

	std::cout << "Main:        " << __FUNCTION__ << ", " << TRACE_VAR(foo.value) << std::endl;

	::foo();

    return 0;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT

Constructor: Foo, value: 20
Main:        main, foo.value: 20
Along:       foo
Constructor: Foo, value: 20

#endif
