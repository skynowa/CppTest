/**
 * \file  CapacityFunction.cpp
 * \brief
 */

#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// Initializing string
    std::string str = "geeksforgeeks is for geeks";

    // Displaying string
    std::cout << "The initial string is : ";
    std::cout << str << std::endl;

    // Resizing string using resize()
    str.resize(13);

    // Displaying string
    std::cout << "The string after resize operation is : ";
    std::cout << str << std::endl;

    // Displaying capacity of string
    std::cout << "The capacity of string is : ";
    std::cout << str.capacity() << std::endl;

    // Decreasing the capacity of string
    // using shrink_to_fit()
    str.shrink_to_fit();

    // Displaying string
    std::cout << "The new capacity after shrinking is : ";
    std::cout << str.capacity() << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

The initial string is : geeksforgeeks is for geeks
The string after resize operation is : geeksforgeeks
The capacity of string is : 26
The new capacity after shrinking is : 15

#endif
