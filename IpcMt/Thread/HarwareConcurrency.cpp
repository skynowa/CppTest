/**
 * \file  HarwareConcurrency.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    const unsigned int threads_num = std::thread::hardware_concurrency();

    std::cout << STD_TRACE_VAR(threads_num) << " concurrent threads are supported" << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

threads_num: 20 concurrent threads are supported

#endif
