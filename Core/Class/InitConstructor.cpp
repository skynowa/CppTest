/**
 * \file  InitConstructor.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class A
{
public:
	A()
	{
		STD_TRACE_FUNC
	}
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	{
		A a;

		std::cout << std::endl;
	}

	{
		A a {};

		std::cout << std::endl;
	}

	{
		A a = {};
		(void)a;

		std::cout << std::endl;
	}

	{
		A a;
		a = {};

		std::cout << std::endl;
	}

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

	::: A :::

	::: A :::

	::: A :::

	::: A :::
	::: A :::

#endif
