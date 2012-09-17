/****************************************************************************
* Class name:  Test
* Description: 
* File name:   Test.h
* Compilers:   Visual C++ 2010 
* String type: Ansi, Unicode
* Libraries:   WinAPI, Stl, XLib
* Author:      Alca
* E-mail:      dr.web.agent@gmail.com
* Created:     01.12.2010 11:39:05
* Version:     1.0.0.0 Debug
*
*****************************************************************************/


#include <xLib/xCommon.h>


//----------------------------------------------------------------------------------------------------
//uiBlackList - list of black IPs
const size_t cuiBlackList[][2] = {
    //#include "__Black_list.lst"
    #include "Black_list.lst"
};
const size_t cuiBlackListSize = xARRAY_SIZE(cuiBlackList);
//----------------------------------------------------------------------------------------------------
//TODO: bIsBot
//NOTE: checking remote user IP (REMOTE_ADDR), заходящего на in.cgi.
//      Входит ли он в любой из диапазанов вышеуказанного массива.
//      Если входит, то дальнейший поиск прекращается и trader_id, который пишется в лог, будет равен 8
//      http://xpoint.ru/forums/programming/perl/misc/thread/32675.xhtml
int
bIsBot(const char *pcszRemoteIp) {
    /*DEBUG*/xASSERT(NULL != pcszRemoteIp);

    /*TRACE*/xTRACE("cuiBlackListSize: %u", cuiBlackListSize);

    const size_t cuiRemoteIp = ntohl(inet_addr(pcszRemoteIp)); 

    /*DEBUG*/xASSERT(- 1 != cuiRemoteIp);

    size_t i;
    for (i = 0 ; i < cuiBlackListSize; ++ i) {
        int bRes = ( cuiBlackList[i][0] == (cuiRemoteIp & cuiBlackList[i][1]) );
        xASSERT(0 == bRes);

        /*TRACE*/xTRACE("Ip: %u, Mask: %u    IsBot: %s", cuiBlackList[i][0], cuiBlackList[i][1], (0 == bRes) ? "FALSE" : "TRUE");
    }

    return EXIT_SUCCESS;
}
//----------------------------------------------------------------------------------------------------
//DONE: main
INT
_tmain(INT iArgc, TCHAR *pszArgv[]) {
    int bRes = - 1;

        const char   cszRemoteIp[] = "209.185.108.10";          // этот IP надо проверить, есть ли он в блэклисте
//        const size_t cuiRemoteIp   = inet_addr(cszRemoteIp);
//        const size_t cuiDbNet      = 3518589952U;               // подсеть       209.185.108
//        const size_t cuiDbMask     = 4294967040U;               // маска подсети 209.185.108
//
//        xTRACE("cuiRemoteIp = %zu, cuiDbNet = %zu", cuiRemoteIp, cuiDbNet);
//
//
//        xTRACE("cszRemoteIp: %s",  cszRemoteIp);
//        xTRACE("cuiRemoteIp: %zu", cuiRemoteIp);
//        xTRACE("cuiDbIp:     %zu", cuiDbNet);
//        xTRACE("cuiDbMask:   %zu", cuiDbMask);
//
//        int bRes = (cuiDbNet == (cuiRemoteIp & cuiDbMask));
//        xTRACE("bRes: %s", (0 == bRes) ? "FALSE" : "TRUE");
//
//        /*
//        $network == ($remote_ip & $mask)
//        */
//
//        /*
//        # проверяемый IP в целочисленном представлении
//        my $ip   = 718768768;
//
//        # проверяемый провайдер
//        my $p    = $providers[$pos];
//        my $net  = $p->[0];
//        my $mask = $p->[1];
//
//        # проверка на вхождение
//        if ($net == ($ip & $mask)) {
//            # нашли. выходим.
//            return 1;
//        }
//        */
//
//        /*for(i = 0; i < sizeof(cuiBlackList) / sizeof(cuiBlackList[0]); ++ i) {
//            if (cuiBlackList[i][0] == (ip_to_check & cuiBlackList[i][1]))
//                printf("Found blacklisted ip: %08X\n", ip_to_check);
//        }*/

        bRes = bIsBot(cszRemoteIp/*cgl_Env->remote_addr*/);


    //--------------------------------------------------
    //TODO: проверить айпи юзера (REMOTE_ADDR) заходящего на in.cgi входит ли он в любой из диапазанов вышеуказанного массива
    //      если входит то дальнейший поиск прекращается и trader_id который пишется в лог будет равен 8

    //system("pause");
	return 0;
}
//----------------------------------------------------------------------------------------------------