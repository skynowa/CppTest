/**
 * \file  VSnprintf.cpp
 * \brief vsnprintf, detect buffer
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int
bufferSize(
	const char *format,
	...
)
{
	int iRv {};

	va_list args;
	va_start(args, format);
	iRv = ::vsnprintf(NULL, 0, format, args);
	va_end(args);

	return iRv + 1; // safe byte for \0
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	int iRv = bufferSize("Width trick: %*d", 5, 10);
	std::cout << TRACE_VAR(iRv) << std::endl;

	return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

iRv: 19

#endif
