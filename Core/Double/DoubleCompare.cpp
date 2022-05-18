 /*
 * \file  DoubleCompare.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    const double v1 = 420.8400001;
    const double v2 = 420.84;

    std::cout << std::setprecision(20) << STD_TRACE_VAR(v1) << std::endl;
    std::cout << std::setprecision(20) << STD_TRACE_VAR(v2) << std::endl;

    std::cout << (v1 > v2 ? "true" : "false") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

v1: 420.84000009999999747
v2: 420.83999999999997499
true

#endif
