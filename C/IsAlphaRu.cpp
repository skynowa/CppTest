/**
 * \file  IsAlphaRu.cpp
 * \brief std::isalpha for russian (ru) text
 *
 * \see   https://cplusplus.com/reference/cctype/isalpha/?kw=isalpha
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    const char str[] = "C++ язык";

    for (const auto it_ch : str) {
        const auto is_alpha = static_cast<bool>( std::isalpha(it_ch) );

        std::cout << "std::isalpha(" << it_ch << ") - " << std::boolalpha << is_alpha <<  std::endl;
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

std::isalpha(C) - true
std::isalpha(+) - false
std::isalpha(+) - false
std::isalpha( ) - false
std::isalpha(�) - false
std::isalpha(�) - false
std::isalpha(�) - false
std::isalpha(�) - false
std::isalpha(�) - false
std::isalpha(�) - false
std::isalpha(�) - false
std::isalpha(�) - false
std::isalpha()  - false

#endif
