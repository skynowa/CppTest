/**
 * \file  IsBot.cpp
 * \brief
 *
 * \todo
 *
 * http://xpoint.ru/forums/programming/perl/misc/thread/32675.xhtml
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//--------------------------------------------------------------------------------------------------
template<class T, size_t N>
constexpr size_t arraySize(T (&)[N]) { return N; }
//--------------------------------------------------------------------------------------------------
constexpr size_t blackList[][2]
{
    #include "Black_list.lst"
};

const size_t blackListSize = arraySize(blackList);
//--------------------------------------------------------------------------------------------------
bool
isBot(const char *a_ip)
{
    STD_TEST_PTR(a_ip);

    std::cout << TRACE_VAR(blackListSize) << std::endl;

    const auto ip = ntohl( inet_addr(a_ip) );
    STD_TEST(ip > 0);

    for (size_t i = 0 ; i < blackListSize; ++ i) {
        const int iRv = ( blackList[i][0] == (ip & blackList[i][1]) );
        if (iRv != 0) {
            return true;
        }

        if (false) {
            const auto _ip   { blackList[i][0] };
            const auto _mask { blackList[i][1] };

            std::cout << TRACE_VAR3(_ip, _mask, iRv) << std::endl;
        }
    }

    return false;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    const char ip[] = "209.185.108.10";

    const bool bRv = ::isBot(ip);
    STD_TEST(bRv);

    std::cout << TRACE_VAR2(ip, bRv) << std::endl;

	return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if 0

blackListSize: 3830
ip: 209.185.108.10, bRv: 1

#endif