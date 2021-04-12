/**
 * \file  main_BlackList.cpp
 * \brief
 *
 * \todo
 */


#include <StdTest.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//-------------------------------------------------------------------------------------------------
template<class T, size_t N>
constexpr size_t arraySize(T (&)[N]) { return N; }

//uiBlackList - list of black IPs
const size_t cuiBlackList[][2] =
{
    #include "Black_list.lst"
};
const size_t cuiBlackListSize = arraySize(cuiBlackList);
//----------------------------------------------------------------------------------------------------
//NOTE: checking remote user IP (REMOTE_ADDR), ???????? in.cgi.
//      ??? ? ? ????? ????? ????????????
//      ?? ???, ? ????? ?????????? ?trader_id, ???????? ??? ??????8
//      http://xpoint.ru/forums/programming/perl/misc/thread/32675.xhtml
int
bIsBot(const char *pcszRemoteIp)
{
    STD_TEST(NULL != pcszRemoteIp);

    printf("cuiBlackListSize: %ld", cuiBlackListSize);

    const size_t cuiRemoteIp = ntohl(inet_addr(pcszRemoteIp));
    STD_TEST(- 1 != cuiRemoteIp);

    for (size_t i = 0 ; i < cuiBlackListSize; ++ i) {
        int bRes = ( cuiBlackList[i][0] == (cuiRemoteIp & cuiBlackList[i][1]) );
        STD_TEST(0 == bRes);

        printf("Ip: %ld, Mask: %ld    IsBot: %s", cuiBlackList[i][0], cuiBlackList[i][1], (0 == bRes) ? "FALSE" : "TRUE");
    }

    return EXIT_SUCCESS;
}
//----------------------------------------------------------------------------------------------------
//DONE: main
int main(int, char **)
{
    int bRes = - 1;

    const char   cszRemoteIp[] = "209.185.108.10";          // ???IP ?? ?????, ?? ? ? ??????
//        const size_t cuiRemoteIp   = inet_addr(cszRemoteIp);
//        const size_t cuiDbNet      = 3518589952U;               // ????       209.185.108
//        const size_t cuiDbMask     = 4294967040U;               // ???????209.185.108
//
//        printf("cuiRemoteIp = %zu, cuiDbNet = %zu", cuiRemoteIp, cuiDbNet);
//
//
//        printf("cszRemoteIp: %s",  cszRemoteIp);
//        printf("cuiRemoteIp: %zu", cuiRemoteIp);
//        printf("cuiDbIp:     %zu", cuiDbNet);
//        printf("cuiDbMask:   %zu", cuiDbMask);
//
//        int bRes = (cuiDbNet == (cuiRemoteIp & cuiDbMask));
//        printf("bRes: %s", (0 == bRes) ? "FALSE" : "TRUE");
//
//        /*
//        $network == ($remote_ip & $mask)
//        */
//
//        /*
//        # ???????IP ???????? ???????//        my $ip   = 718768768;
//
//        # ????????????//        my $p    = $providers[$pos];
//        my $net  = $p->[0];
//        my $mask = $p->[1];
//
//        # ???? ? ?????//        if ($net == ($ip & $mask)) {
//            # ???. ????.
//            return 1;
//        }
//        */
//
//        /*for(i = 0; i < sizeof(cuiBlackList) / sizeof(cuiBlackList[0]); ++ i) {
//            if (cuiBlackList[i][0] == (ip_to_check & cuiBlackList[i][1]))
//                printf("Found blacklisted ip: %08X\n", ip_to_check);
//        }*/

        bRes = bIsBot(cszRemoteIp/*cgl_Env->remote_addr*/);

	return 0;
}
//----------------------------------------------------------------------------------------------------
