/**
 * \file  CtorByFunctionPointer.cpp
 * \brief
 *
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
const int threadsNum {3};
//--------------------------------------------------------------------------------------------------
void worker()
{
    for (int i = 0; i < ::threadsNum; ++ i) {
        std::cout << "worker Executing - " << i << std::endl;
    }
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::thread t(worker);

    for (int i = 0; i < ::threadsNum; ++ i) {
        std::cout << "Display From MainThread" << std::endl;
    }

    t.join();

    std::cout << "Exit of Main function" << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

---------------------------------------------
Display From MainThread
Display From MainThread
Display From MainThread
worker Executing - 0
worker Executing - 1
worker Executing - 2
Exit of Main function
---------------------------------------------

#endif
