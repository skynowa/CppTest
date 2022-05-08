/**
 * \file  Proxy.cpp
 * \brief
 *
 * \review
 *
 * Proxy allows one object to stand for something else.
 * So whilst you think you are dealing with one object,
 * you are actually dealing with something else.
 * In this example, CoutProxy stands for std::cout.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class ProxyCout
{
public:
	void write(const std::string &str) const
	{
		std::cout << str;
	}
};
//--------------------------------------------------------------------------------------------------
void hello_world(const ProxyCout &a_cout)
{
	a_cout.write("Hello world!\n");
}
//--------------------------------------------------------------------------------------------------
int main()
{
	hello_world( ProxyCout() );

	return 0;
}
//--------------------------------------------------------------------------------------------------
