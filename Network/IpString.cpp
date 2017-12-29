/**
 * \file  main.cpp
 * \brief
 */


#include <StdTest.h>
#include <arpa/inet.h>
#include <cmath>

//-------------------------------------------------------------------------------------------------
int main(int argsNum, char **args)
{
	// to int
	const std::string ip     = "92.60.182.205";
	const uint32_t    ip_int = ::inet_network(ip.c_str());

	std::cout << STD_TRACE_VAR(ip_int) << std::endl;

	// to string
	struct in_addr ip_addr;
	ip_addr.s_addr = ::htonl(ip_int);

	std::string ip_str = inet_ntoa(ip_addr);

	std::cout << STD_TRACE_VAR(ip_str) << std::endl;

	return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

ip_int: 1547482829
ip_str: 92.60.182.205

#endif

