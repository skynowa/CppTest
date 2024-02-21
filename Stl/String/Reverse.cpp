/**
 * \file  Reverse.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//---------------------------------------------------------------------------
int main(int, char **)
{
    char str[] = "12345";

    std::reverse(&str[0], &str[5]);

    std::cout << STD_TRACE_VAR(str) << std::endl;

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

str: 54321

#endif
