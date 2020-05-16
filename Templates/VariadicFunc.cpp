/**
 * \file  main.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>

//-------------------------------------------------------------------------------------------------
void
foo()
{
	std::cout << TRACE_VAR(__FUNCTION__) << std::endl;
}
//-------------------------------------------------------------------------------------------------
void
foo(int i)
{
	std::cout << TRACE_VAR2(__FUNCTION__, i) << std::endl;
}
//-------------------------------------------------------------------------------------------------
void
foo(int i, const char *c)
{
	std::cout << TRACE_VAR3(__FUNCTION__, i, c) << std::endl;
}
//-------------------------------------------------------------------------------------------------
void
foo(int i, double d, void *ptr)
{
	std::cout << TRACE_VAR4(__FUNCTION__, i, d, ptr) << std::endl;
}
//-------------------------------------------------------------------------------------------------
template<typename ...ArgsT>
void
foo(const char *format, const ArgsT &...args)
{
	constexpr std::size_t argsSize = sizeof...(ArgsT);

	std::cout << TRACE_VAR2(format, argsSize) << ": ";

	// Unpack the arguments for further treatment
    foo(args...);
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	foo("format0");
	foo("format1", 1);
	foo("format2", 2, "bbb");
	foo("format3", 3, 3.0, nullptr);

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

format: format0, argsSize: 0: __FUNCTION__: foo
format: format1, argsSize: 1: __FUNCTION__: foo, i: 1
format: format2, argsSize: 2: __FUNCTION__: foo, i: 2, c: bbb
format: format3, argsSize: 3: __FUNCTION__: foo, i: 3, d: 3, ptr: 0

#endif
