/**
 * \file  SizeofUnicodes.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::cout << TRACE_VAR(sizeof(L'\0')) << std::endl;
    std::cout << TRACE_VAR(sizeof(L'0'))  << std::endl;
    std::cout << TRACE_VAR(sizeof(0))     << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

sizeof(L'\0'): 4
sizeof(L'0'):  4
sizeof(0):     4

#endif
