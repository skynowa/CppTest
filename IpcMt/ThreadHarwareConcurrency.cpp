/**
 * \file  ThreadHarwareConcurrency.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    const unsigned int threads_num = std::thread::hardware_concurrency();

    std::cout << threads_num << " concurrent threads are supported.\n";

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

20 concurrent threads are supported.

#endif
