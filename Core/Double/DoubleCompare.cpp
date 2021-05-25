 /*
 * \file  DoubleCompare.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    double v1 = 420.8400001;
    double v2 = 420.84;

    std::cout << std::setprecision(20) << TRACE_VAR(v1) << std::endl;
    std::cout << std::setprecision(20) << TRACE_VAR(v2) << std::endl;

    if (v1 > v2) {
        std::cout << "true"  << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

v1: 420.84000009999999747
v2: 420.83999999999997499
true

#endif
