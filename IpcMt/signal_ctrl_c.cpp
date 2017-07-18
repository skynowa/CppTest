/**
 * \file  main.cpp
 * \brief
 */


#include "../StdTest.h"

#include <signal.h>
#include <iostream>
#include <cstdlib>
//-------------------------------------------------------------------------------------------------
bool isStop = false;
//-------------------------------------------------------------------------------------------------
void
handler(
	const int a_signalNum
)
{
    std::cout << "\n" << STD_TRACE_VAR(a_signalNum) << std::endl;

    ::isStop = true;
}
//-------------------------------------------------------------------------------------------------
class A
{
public:
	A() {
		std::cout << __FUNCTION__ << std::endl;
	}

	~A() {
		std::cout << __FUNCTION__ << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
int main(int argsNum, char **args)
{
	A a;

	signal(SIGINT, &::handler);

	while ( !::isStop ) {}

	std::cout << "main - exit" << std::endl;

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

A
^C
a_signalNum: 2
main - exit
~A

#endif
