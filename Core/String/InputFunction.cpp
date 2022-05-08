/**
 * \file  InputFunction.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::string str = "AAA";

	std::cout << "The String is: " << str << std::endl;

	str.push_back('s');
	std::cout <<"The string after push back operation is: " << str << std::endl;

	str.pop_back();
	std::cout <<"The string after pop back operation is: " << str << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

The String is: AAA
The string after push back operation is: AAAs
The string after pop back operation is: AAA

#endif
