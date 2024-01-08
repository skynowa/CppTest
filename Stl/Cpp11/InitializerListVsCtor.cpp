/**
 * \file  InitializerListVsCtor.cpp
 * \brief
 *
 * \see   https://www.learncpp.com/cpp-tutorial/stdinitializer_list/
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class Foo
{
public:
	explicit Foo(int, int)
	{
		STD_TRACE_FUNC_PRETTY;
	}

    // If this ctor don't exists - Calls Foo::Foo(int, int)
	explicit Foo(std::initializer_list<int>)
	{
		STD_TRACE_FUNC_PRETTY;
	}
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    Foo f1(1, 2); // Calls Foo::Foo(int, int)
	Foo f2{1, 2}; // Calls Foo(std::initializer_list<int>)

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

	::: Foo::Foo(int, int) :::
	::: Foo::Foo(std::initializer_list<int>) :::

#endif
