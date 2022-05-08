/**
 * \file  IpString.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <arpa/inet.h>
#include <cmath>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const std::string ip = "92.60.182.205";

	// to int
	uint32_t ip_int {};
	{
		ip_int = ::inet_network( ip.c_str() );
		STD_TEST(ip_int == 1547482829);

		std::cout << TRACE_VAR(ip_int) << std::endl;
	}

	// to string
	{
		struct in_addr ip_addr {};
		ip_addr.s_addr = ::htonl(ip_int);

		std::string ip_str = inet_ntoa(ip_addr);
		STD_TEST(ip_str == ip);

		std::cout << TRACE_VAR(ip_str) << std::endl;
	}

	return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

ip_int: 1547482829
ip_str: 92.60.182.205

#endif
