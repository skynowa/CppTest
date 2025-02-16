/**
 * \file  CreationByFunctionPointer.cpp
 * \brief
 *
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
void worker()
{
    for (int i = 0; i < 10; ++ i) {
        std::cout << "worker Executing - " << i << std::endl;
    }
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::thread t(worker);

    for (int i = 0; i < 10; ++ i) {
        std::cout << "Display From MainThread" << std::endl;
    }

    t.join();

    std::cout << "Exit of Main function" << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Display From MainThreadworker Executing -
Display From MainThread
Display From MainThread
Display From MainThread
Display From MainThread
Display From MainThread
0Display From MainThread

worker Executing - 1
worker Executing - 2
worker Executing - 3
worker Executing - 4
worker Executing - 5
worker Executing - 6
worker Executing - 7
worker Executing - 8
worker Executing - 9
Display From MainThread
Display From MainThread
Display From MainThread
Exit of Main function

#endif
