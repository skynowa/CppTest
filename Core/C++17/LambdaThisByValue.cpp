/**
 * \file  main.cpp
 * \brief Lambda capture this by value
 *
 * \todo
 *
 * Capturing this in a lambda's environment was previously reference-only. An example of where
 * this is problematic is asynchronous code using callbacks that require an object to be available,
 * potentially past its lifetime. *this (C++17) will now make a copy of the current object,
 * while this (C++11) continues to capture by reference.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
struct MyObj
{
	int value {123};

	auto getValueCopy()
	{
		return [*this] { return value; };
	}

	auto getValueRef()
	{
		return [this] { return value; };
	}
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	MyObj mo;
	auto valueCopy = mo.getValueCopy();
	auto valueRef = mo.getValueRef();
	mo.value = 321;
	valueCopy(); // 123
	valueRef(); // 321

    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
