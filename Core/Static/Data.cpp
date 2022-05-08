/**
 * \file  Data.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
static char buff1[10] {};
static char buff2[10];
//--------------------------------------------------------------------------------------------------
void foo()
{
    static char buff1[10 + 1] {};
    static char buff2[10 + 1];

    std::cout << TRACE_VAR(buff1) << std::endl;
    std::cout << TRACE_VAR(buff2) << std::endl;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    static char buff3[10 + 1] {};
    static char buff4[10 + 1];

    ::foo();

    std::cout << TRACE_VAR(::buff1) << std::endl;
    std::cout << TRACE_VAR(::buff2) << std::endl;
    std::cout << TRACE_VAR(buff3) << std::endl;
    std::cout << TRACE_VAR(buff4) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

buff1:
buff2:
::buff1:
::buff2:
buff3:
buff4:

#endif
