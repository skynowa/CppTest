/**
 * \file  main.cpp
 * \brief vsnprintf, detect buffer
 */

#include <stdio.h>
#include <stdarg.h>
#include <iostream>
#include <string>
#include <iostream>
#include <assert.h>

//-------------------------------------------------------------------------------------------------
#define TRACE_VAR(v) \
    #v ": " << (v)
//-------------------------------------------------------------------------------------------------
int
bufferSize(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int result = vsnprintf(NULL, 0, format, args);
    va_end(args);

    return result + 1; // safe byte for \0
}
//-------------------------------------------------------------------------------------------------
int main(int argsNum, char **args)
{
	int iRv = bufferSize("Width trick: %*d", 5, 10);

	std::cout << TRACE_VAR(iRv) << std::endl;

	return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

iRv: 19

#endif
