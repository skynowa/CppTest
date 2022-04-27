/**
 * \file  Time.cpp
 * \brief
 *
 * \review
 */


#include <iostream>

#include <stdio.h>
#include <time.h>
#include <cstring>
//--------------------------------------------------------------------------------------------------
// 2008-09-25 11:38:44     Test string
void
logEntry(const char *message)
{
	// Output date and time in ISO 8601:2004 format, i.e., YYYY-MM-DD HH:MM:SS
	const char *timeStringFormat = "%Y-%m-%d %H:%M:%S";
	const int   timeStringLength = 20;
	char        timeString[timeStringLength] {};

	// get current date and time
	time_t  t       = time(0);
	tm     *curTime = localtime(&t);

	strftime(timeString, timeStringLength, timeStringFormat, curTime);
	std::cout << timeString << '\t' << message << '\n';
}
//--------------------------------------------------------------------------------------------------
void
msecToTimeStr(int iMsec)
{
	#define HOUR(time) ((uint16_t)((uint32_t)(time) / 3600000))
	#define MIN(time)  ((uint16_t)(((uint32_t)(time) % 3600000) / 60000))
	#define SEC(time)  ((uint16_t)((((uint32_t)(time) % 3600000) % 60000) / 1000))
	#define MSEC(time) ((uint16_t)((uint32_t)(time) % 1000))

    char buf1[64] {};
    sprintf(buf1, "%u:%.2u:%.2u:%.3u", HOUR(iMsec), MIN(iMsec), SEC(iMsec), MSEC(iMsec));

    std::cout << buf1 << '\t' << "message" << '\n';

	char buf[64] {};
    unsigned int h {}, m {}, s {}, ms {};
    unsigned int t = iMsec;

   /**
    * 1 000 ms    = 1 sec
    * 60 000 ms   = 1 min
    * 3600 000 ms = 1 h
	*/

    h  = t / 3600000;
    m  = t % 3600000 / 60000;
    s  = t % 60000 / 1000;
    ms = t % 1000;

    sprintf(buf, "%u:%.2u:%.2u:%.3u", h, m, s, ms);

    std::cout << buf << '\t' << "message" << '\n';
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	::msecToTimeStr(13437658);

	return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

3:43:57:658	message
3:43:57:658	message

#endif