/**
 * \file  OtherUsefulFunction.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::string str("GeeksforGeeks");
    std::string str1("GeeksforGeeks");

    // Comparing strings using compare()
    if (str.compare(str1) == 0)
        std::cout << "Strings are equal";
    else
        std::cout << "Strings are unequal";

    std::string str2("The Geeks for Geeks");

    // find() returns position to first
    // occurrence of substring "Geeks"
    // Prints 4
    std::cout << "First occurrence of \"Geeks\" starts from : ";
    std::cout << str2.find("Geeks") << std::endl;

    // Prints position of first occurrence of
    // any character of "reef" (Prints 2)
    std::cout << "First occurrence of character from \"reef\" is at : ";
    std::cout << str2.find_first_of("reef") << std::endl;

    // Prints position of last occurrence of
    // any character of "reef" (Prints 16)
    std::cout << "Last occurrence of character from \"reef\" is at : ";
    std::cout << str2.find_last_of("reef") << std::endl;

    // rfind() returns position to last
    // occurrence of substring "Geeks"
    // Prints 14
    std::cout << "Last occurrence of \"Geeks\" starts from : ";
    std::cout << str2.rfind("Geeks") << std::endl;

    std::string str3("Geeksfor");

    // Printing the original string
    std::cout << str3 << std::endl;

    // Inserting "for" at 5th position
    str3.insert(8,"Geeks");

    // Printing the modified string
    // Prints "GeeksforGeeks"
    std::cout << str3 << std::endl;

    //Clearing the string
    str3.clear();

    //Checking if string is empty. Returns a boolean value.
    if (str3.empty() ==true)	//This also works. str3.empty()==1
    	std::cout << "The string is Empty" << std::endl;
    else
    	std::cout <<"The string is not empty." << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Strings are equalFirst occurrence of "Geeks" starts from : 4
First occurrence of character from "reef" is at : 2
Last occurrence of character from "reef" is at : 16
Last occurrence of "Geeks" starts from : 14
Geeksfor
GeeksforGeeks
The string is Empty

#endif
