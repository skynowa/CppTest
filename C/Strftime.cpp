/**
 * \file  Strftime.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
void
logEntry()
{
	const std::size_t dateSize {80};
	char              date[dateSize] {};

	// get current date and time
	const std::time_t  curTime   = std::time(nullptr);
	const std::tm     *localTime = std::localtime(&curTime);

	std::strftime(date, dateSize - 1, "%Y-%m-%d %H:%M:%S", localTime);

	std::cout << STD_TRACE_VAR(date) << '\n';
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    ::logEntry();

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

2022-04-27 15:56:19	test

#endif
