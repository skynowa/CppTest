/**
 * \file  IfDecInc.cpp
 * \brief If with post/pre increment operators
 *
 * If i == 0 - ++ i would increment before evaluation, i ++ increments - after
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    int n {};

    std::cout << "[#1] " << STD_TRACE_VAR(n) << std::endl;

    if (n ++) {
        std::cout << "[#2] " << STD_TRACE_VAR(n) << std::endl;
    }

    std::cout << "[#3] " << STD_TRACE_VAR(n) << std::endl;

    if (n --) {
        std::cout << "[#4] " << STD_TRACE_VAR(n) << std::endl;
    }

    std::cout << "[#5] " << STD_TRACE_VAR(n) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

[#1] n: 0
[#2] - skip
[#3] n: 1
[#4] n: 0
[#5] n: 0

#endif
