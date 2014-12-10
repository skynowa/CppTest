 /*
 * \file  DoubleCompare.cpp
 * \brief
 */


#include <string>
#include <iostream>
#include <assert.h>
#include <iomanip>      // std::setprecision

//-------------------------------------------------------------------------------------------------
#define TRACE_VAR(v) \
    #v ": " << (v)
//-------------------------------------------------------------------------------------------------
int main(int argsNum, char **args)
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


    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

v1: 420.84000009999999747
v2: 420.83999999999997499
true

#endif

