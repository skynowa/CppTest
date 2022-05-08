/**
 * \file  IteratorFunction.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// Initializing string`
    std::string str = "geeksforgeeks";

    // Declaring iterator
    // Displaying string
    std::cout << "The string using forward iterators is : ";
    for (std::string::iterator it = str.begin(); it != str.end(); ++ it) {
        std::cout << *it;
    }
    std::cout << std::endl;

    // Declaring reverse iterator
    // Displaying reverse string
    std::cout << "The reverse string using reverse iterators is : ";
    for (std::string::reverse_iterator it1 = str.rbegin(); it1 != str.rend(); ++ it1) {
        std::cout << *it1;
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

The string using forward iterators is : geeksforgeeks
The reverse string using reverse iterators is : skeegrofskeeg

#endif
