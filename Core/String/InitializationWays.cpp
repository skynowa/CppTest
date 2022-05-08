/**
 * \file  InitializationWays.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// various constructor of string class

    // initialization by raw string
    std::string str1("first string");

    // initialization by another string
    std::string str2(str1);

    // initialization by character with number of occurence
    std::string str3(5, '#');

    // initialization by part of another string
    // from 6th index (second parameter)
    // 6 characters (third parameter)
    std::string str4(str1, 6, 6);

    // initialization by part of another string : iteartor version
    std::string str5(str2.begin(), str2.begin() + 5);

    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
    std::cout << str3 << std::endl;
    std::cout << str4 << std::endl;
    std::cout << str5 << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

first string
first string
#####
string
first

#endif
