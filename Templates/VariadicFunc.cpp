/**
 * \file  main.cpp
 * \brief
 */


#include <StdTest.h>

//-------------------------------------------------------------------------------------------------
void
foo()
{
	std::cout << STD_TRACE_VAR(__FUNCTION__) << std::endl;
}
//-------------------------------------------------------------------------------------------------
void
foo(int i)
{
	std::cout << STD_TRACE_VAR2(__FUNCTION__, i) << std::endl;
}
//-------------------------------------------------------------------------------------------------
void
foo(int i, const char *c)
{
	std::cout << STD_TRACE_VAR3(__FUNCTION__, i, c) << std::endl;
}
//-------------------------------------------------------------------------------------------------
void
foo(int i, double d, void *ptr)
{
	std::cout << STD_TRACE_VAR4(__FUNCTION__, i, d, ptr) << std::endl;
}
//-------------------------------------------------------------------------------------------------
template<typename ...ArgsT>
void
foo(const char *format, const ArgsT &...args)
{
	constexpr std::size_t argsSize = sizeof...(ArgsT);

	std::cout << STD_TRACE_VAR2(format, argsSize) << ": ";

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



#endif
