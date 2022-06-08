/**
 * \file  Strftime.cpp
 * \brief format date and time
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
void
logEntry()
{
	const std::size_t dateSize {80};
	char              date[dateSize + 1] {};

	// get current date and time
	const std::time_t  curTime   = std::time(nullptr);
	const std::tm     *localTime = std::localtime(&curTime);

	std::strftime(date, dateSize, "%Y-%m-%d %H:%M:%S", localTime);

	std::cout << STD_TRACE_VAR(date) << std::endl;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    ::logEntry();

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

date: 2022-06-09 02:01:07

#endif
