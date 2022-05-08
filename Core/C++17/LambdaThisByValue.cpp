/**
 * \file  main.cpp
 * \brief Lambda capture this by value
 *
 * Capturing this in a lambda's environment was previously reference-only. An example of where
 * this is problematic is asynchronous code using callbacks that require an object to be available,
 * potentially past its lifetime. *this (C++17) will now make a copy of the current object,
 * while this (C++11) continues to capture by reference.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
struct A
{
	int value {123};

	auto valueCopy() const
	{
		STD_TRACE_FUNC;

		return
			[*this]() -> int
			{
				return value;
			};
	}

	auto valueRef() const
	{
		STD_TRACE_FUNC;

		return
			[this]() -> int
			{
				return value;
			};
	}
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	A a;

	const auto funcCopy = a.valueCopy();
	const auto funceRef = a.valueRef();

	a.value = 321;

	std::cout << TRACE_VAR(funcCopy()) << std::endl;
	std::cout << TRACE_VAR(funceRef()) << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

	::: valueCopy :::
	::: valueRef :::

funcCopy(): 123
funceRef(): 321

#endif
