/**
 * \file  ConvertTime.cpp
 * \brief
 *
 * \review
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
#define HOUR(time) ((uint16_t)((uint32_t)(time) / 3600000))
#define MIN(time)  ((uint16_t)(((uint32_t)(time) % 3600000) / 60000))
#define SEC(time)  ((uint16_t)((((uint32_t)(time) % 3600000) % 60000) / 1000))
#define MSEC(time) ((uint16_t)((uint32_t)(time) % 1000))
//--------------------------------------------------------------------------------------------------
void
msecToTimeStr(int iMsec)
{
    char buf1[80] {};
    sprintf(buf1, "%u:%.2u:%.2u:%.3u", HOUR(iMsec), MIN(iMsec), SEC(iMsec), MSEC(iMsec));

    std::cout << buf1 << '\t' << "message" << '\n';

	char buf[80] {};
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