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
format(int i, double d, char ch)
{
	std::cout << "[format3]: " << TRACE_VAR3(i, d, ch) << std::endl;
}
//-------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------
template<typename ...ArgsT>
void
formatStr14(const char *fmt, const ArgsT &...args)
{
	constexpr std::size_t argsSize = sizeof...(ArgsT);

	std::cout << __FUNCTION__ << ": " << TRACE_VAR2(fmt, argsSize) << ": ";

	// Unpack the arguments for further treatment
    format(args...);
}

template<typename ...ArgsT>
void
formatStr17(const char *fmt, const ArgsT &...args)
{
	std::cout << __FUNCTION__ << ": ";

    ((std::cout << fmt << ", " << args << ", "), ...);
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
#if 1
	formatStr14("fmt0");
	formatStr14("fmt1", 100);
	formatStr14("fmt2", 200, "bbb");
	formatStr14("fmt3", 300, 300.0, 'a');
#else
	formatStr17("fmt0");					std::cout << std::endl;
	formatStr17("fmt1", 100);				std::cout << std::endl;
	formatStr17("fmt2", 200, "bbb");		std::cout << std::endl;
	formatStr17("fmt3", 300, 300.0, 'a');	std::cout << std::endl;
#endif

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

formatStr14: fmt: fmt0, argsSize: 0: [format0]: [n/a]
formatStr14: fmt: fmt1, argsSize: 1: [format1]: i: 100
formatStr14: fmt: fmt2, argsSize: 2: [format2]: i: 200, c: bbb
formatStr14: fmt: fmt3, argsSize: 3: [format3]: i: 300, d: 300, ch: a

formatStr17:
formatStr17: fmt1, 100,
formatStr17: fmt2, 200, fmt2, bbb,
formatStr17: fmt3, 300, fmt3, 300, fmt3, a,

#endif
