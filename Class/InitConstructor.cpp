/**
 * \file  main.cpp
 * \brief
 */


#include <StdTest.h>

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

		std::cout << std::endl;
	}

	{
		A a;
		a = {};

		std::cout << std::endl;
	}

    // std::cout << STD_TRACE_VAR("") << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

	::: A :::

	::: A :::

	::: A :::

	::: A :::
	::: A :::

#endif

