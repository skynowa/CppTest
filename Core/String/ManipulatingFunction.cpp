/**
 * \file  ManipulatingFunction.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// Initializing 1st string
    std::string str1 = "geeksforgeeks is for geeks";

    // Declaring 2nd string
    std::string str2 = "geeksforgeeks rocks";

    // Declaring character array
    char ch[80];

    // using copy() to copy elements into char array
    // copies "geeksforgeeks"
    str1.copy(ch, 13, 0);

    // Diplaying char array
    std::cout << "The new copied character array is : ";
    std::cout << ch << std::endl << std::endl;

    // Displaying strings before swapping
    std::cout << "The 1st string before swapping is : ";
    std::cout << str1 << std::endl;
    std::cout << "The 2nd string before swapping is : ";
    std::cout << str2 << std::endl;

    // using swap() to swap string content
    str1.swap(str2);

    // Displaying strings after swapping
    std::cout << "The 1st string after swapping is : ";
    std::cout << str1 << std::endl;
    std::cout << "The 2nd string after swapping is : ";
    std::cout << str2 << std::endl;

    std::cout << "=======================\n" << std::endl;

    std::string stra = "first string";
    std::string str4(stra, 6, 6);
    std::string str6 = str4;
    // append add the argument string at the end
    str6.append(" extension");
    //  same as str6 += " extension"

    // another version of appends, which appends part of other
    // string
    str4.append(str6, 0, 6);  // at 0th position 6 character

    std::cout << str6 << std::endl;
    std::cout << str4 << std::endl;

    //  find returns index where pattern is found.
    //  If pattern is not there it returns predefined
    //  constant npos whose value is -1

    if (str6.find(str4) != std::string::npos)
        std::cout << "str4 found in str6 at " << str6.find(str4)
             << " pos" << std::endl;
    else
        std::cout << "str4 not found in str6" << std::endl;

    //  substr(a, b) function returns a substring of b length
    //  starting from index a
    std::cout << str6.substr(7, 3) << std::endl;

    //  if second argument is not passed, string till end is
    // taken as substring
    std::cout << str6.substr(7) << std::endl;

    //  erase(a, b) deletes b character at index a
    str6.erase(7, 4);
    std::cout << str6 << std::endl;

    //  iterator version of erase
    str6.erase(str6.begin() + 5, str6.end() - 3);
    std::cout << str6 << std::endl;

    str6 = "This is a examples";

    //  replace(a, b, str)  replaces b character from a index by str
    str6.replace(2, 7, "ese are test");

    std::cout << str6 << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

The new copied character array is : geeksforgeeksU

The 1st string before swapping is : geeksforgeeks is for geeks
The 2nd string before swapping is : geeksforgeeks rocks
The 1st string after swapping is : geeksforgeeks rocks
The 2nd string after swapping is : geeksforgeeks is for geeks
=======================

string extension
stringstring
str4 not found in str6
ext
extension
string nsion
strinion
These are test examples

#endif
