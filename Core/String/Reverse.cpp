/**
 * \file  Reverse.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
// Function to reverse a string
void reverseStr(std::string &str)
{
    const std::size_t n = str.size();

    // Swap character starting from two corners
    for (std::size_t i = 0; i < n / 2; ++ i) {
        std::swap(str[i], str[n - i - 1]);
    }
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::string str = "abcdef";
    std::cout << str << " -> ";

    // Using the built-in reverse Function:
    // std::reverse(str.begin(), str.end());
    ::reverseStr(str);

    std::cout << str << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

abcdef -> fedcba

#endif
