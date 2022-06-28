/**
 * \file  DiffIDs.cpp
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
    std::cout << "Thread: ID  = " << std::this_thread::get_id() << std::endl;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::thread t1(worker);
    std::thread t2(worker);

    if (t1.get_id() != t2.get_id()) {
        std::cout << "Both Threads have different IDs" << std::endl;
    }

    std::cout << "Main: ID of Thread 1 = " << t1.get_id() << std::endl;
    std::cout << "Main: ID of Thread 2 = " << t2.get_id() << std::endl;

    t1.join();
    t2.join();

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Thread: ID  = 140613060937472
Thread: ID  = 140613052544768

Both Threads have different IDs

Main: ID of Thread 1 = 140613060937472
Main: ID of Thread 2 = 140613052544768

#endif
