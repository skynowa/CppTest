/**
 * \file  SizeofUnicodes.cpp
 * \brief
 *
 * \todo
 */


#include <StdStream.h>
#include <StdTest.h>
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

sizeof(_T('|0')) = 4
sizeof(_T('0'))  = 4
sizeof(0)        = 4

#endif
