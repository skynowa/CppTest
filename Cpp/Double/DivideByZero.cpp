/**
 * \file  DivideByZero.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    const double a = 1.0 / 0.0; // inf
    std::cout << STD_TRACE_VAR(a) << std::endl;

    const double b = -1.0 / 0.0; // -inf
    std::cout << STD_TRACE_VAR(b) << std::endl;

    const double c = 0.0 / 0.0; // -nan
    std::cout << STD_TRACE_VAR(c) << std::endl;

    const double d1 = 10.0 / 0.0; // inf
    std::cout << STD_TRACE_VAR(d1) << std::endl;

#if 0
    const double d2 = 10.0 / 0; // error: division by zero [-Werror=div-by-zero]
    std::cout << STD_TRACE_VAR(d2) << std::endl;
#endif

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

a: inf
b: -inf
c: -nan
d1: inf

#endif
