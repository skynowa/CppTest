/**
 * \file  DiffIDs.cpp
 * \brief Main thread ID diffs with worker ID
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
void worker()
{
    std::cout << "[worker] Thread ID = " << std::this_thread::get_id() << std::endl;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::thread t1(worker);
    std::thread t2(worker);

    if (t1.get_id() != t2.get_id()) {
        std::cout << "Both Threads have different IDs" << std::endl;
    }

    std::cout << "ID of Thread 1 = " << t1.get_id() << std::endl;
    std::cout << "ID of Thread 2 = " << t2.get_id() << std::endl;

    t1.join();
    t2.join();

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

---------------------------------------------
Both Threads have different IDs
ID of Thread 1 = 140103492044352
ID of Thread 2 = 140103481558592
[worker] Thread ID  = 140103492044352
[worker] Thread ID  = 140103481558592
---------------------------------------------

#endif
