/**
 * \file  main.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>

//-------------------------------------------------------------------------------------------------
void
format()
{
	std::cout << "[format0]: " << "[n/a]" << std::endl;
}
//-------------------------------------------------------------------------------------------------
void
format(int i)
{
	std::cout << "[format1]: " << TRACE_VAR(i) << std::endl;
}
//-------------------------------------------------------------------------------------------------
void
format(int i, const char *c)
{
	std::cout << "[format2]: " << TRACE_VAR2(i, c) << std::endl;
}
//-------------------------------------------------------------------------------------------------
void
format(int i, double d, void *ptr)
{
	std::cout << "[format3]: " << TRACE_VAR3(i, d, ptr) << std::endl;
}
//-------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------
template<typename ...ArgsT>
void
formatStr(const char *fmt, const ArgsT &...args)
{
	constexpr std::size_t argsSize = sizeof...(ArgsT);

	std::cout << "[formatStr...]: " << TRACE_VAR2(fmt, argsSize) << ": ";

	// Unpack the arguments for further treatment
    format(args...);
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	formatStr("fmt0");
	formatStr("fmt1", 1);
	formatStr("fmt2", 2, "bbb");
	formatStr("fmt3", 3, 3.0, nullptr);

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

[formatStr...]: fmt: fmt0, argsSize: 0: [format0]: [n/a]
[formatStr...]: fmt: fmt1, argsSize: 1: [format1]: i: 1
[formatStr...]: fmt: fmt2, argsSize: 2: [format2]: i: 2, c: bbb
[formatStr...]: fmt: fmt3, argsSize: 3: [format3]: i: 3, d: 3, ptr: 0

#endif
