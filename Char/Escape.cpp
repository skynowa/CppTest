/**
 * \file  main.cpp
 * \brief
 */


#include <StdTest.h>

//-------------------------------------------------------------------------------------------------
int main(int argsNum, char **args)
{
	std::string s1 = "aaa'bbb'ccc";
	std::string s2 = "aaa\'bbb\'ccc";
	std::string s3 = "aaa\"bbb\"ccc";
	// std::string s4 = "aaa"bbb"ccc"; - not complied

    std::cout << STD_TRACE_VAR(s1) << std::endl;
    std::cout << STD_TRACE_VAR(s2) << std::endl;
    std::cout << STD_TRACE_VAR(s3) << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

s1: aaa'bbb'ccc
s2: aaa'bbb'ccc
s3: aaa"bbb"ccc

#endif

