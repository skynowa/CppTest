/**
 * \file  TimeFormat.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    ::setenv("TZ", "/usr/share/zoneinfo/America/Los_Angeles", 1); // POSIX-specific

    std::tm tm {};

    // date
    tm.tm_year  = 2020 - 1900; // 2020
    tm.tm_mon   = 2 - 1; // Feb
    tm.tm_mday  = 15;

    // time
    tm.tm_hour  = 10;
    tm.tm_min   = 15;

    // Etc
    tm.tm_isdst = 0; // Not daylight saving

    std::time_t t = std::mktime(&tm);

    std::cout << "UTC:   " << std::put_time(std::gmtime(&t),    "%c %Z") << std::endl;
    std::cout << "Local: " << std::put_time(std::localtime(&t), "%c %Z") << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

UTC:   Sat Feb 15 18:15:00 2020 GMT
Local: Sat Feb 15 10:15:00 2020 PST

#endif
