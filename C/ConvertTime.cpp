/**
 * \file  ConvertTime.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
#define HOUR(time) ((uint16_t)((uint32_t)(time) / 3600000))
#define MIN(time)  ((uint16_t)(((uint32_t)(time) % 3600000) / 60000))
#define SEC(time)  ((uint16_t)((((uint32_t)(time) % 3600000) % 60000) / 1000))
#define MSEC(time) ((uint16_t)((uint32_t)(time) % 1000))
//--------------------------------------------------------------------------------------------------
void
msecToTimeStr(const int a_msec)
{
    char buf1[80] {};
    sprintf(buf1, "%u:%.2u:%.2u:%.3u", HOUR(a_msec), MIN(a_msec), SEC(a_msec), MSEC(a_msec));

    std::cout << buf1 << '\t' << "message" << '\n';

    unsigned int h {}, m {}, s {}, ms {};

   /**
    * 1 000 ms    = 1 sec
    * 60 000 ms   = 1 min
    * 3600 000 ms = 1 h
	*/

    h  = a_msec / 3600000;
    m  = a_msec % 3600000 / 60000;
    s  = a_msec % 60000 / 1000;
    ms = a_msec % 1000;

	char buf[80] {};
    sprintf(buf, "%u:%.2u:%.2u:%.3u", h, m, s, ms);

    std::cout << buf << '\t' << "message" << std::endl;
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