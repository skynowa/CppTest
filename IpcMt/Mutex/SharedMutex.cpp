/**
 * \file  SharedMutex.cpp
 * \brief std::shared_mutex
 *
 * By use of normal mutexes, you can guarantee exclusive access to some kind of critical resource -
 * and nothing else.
 * Shared mutexes extend this feature by allowing two levels of access:
 *
 * - Exclusive (unique_lock<shared_mutex>):
 *
 *   Access prevents any other thread from acquiring the mutex, just as with the
 *   normal mutex. It does not matter if the other thread tries to acquire shared or exclusive access.
 *
 * - Shared (shared_lock<shared_mutex>):
 *
 *   Shared access allows multiple threads to acquire the mutex, but all of them
 *   only in shared mode. Exclusive access is not granted until all of the previous shared holders
 *   have returned the mutex (typically, as long as an exclusive request is waiting,
 *   new shared ones are queued to be granted after the exclusive access).
 *
 * \std   C++17
 * \see   https://en.cppreference.com/w/cpp/thread/shared_mutex
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    // STD_TRACE_FUNC;

    // std::cout << STD_TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
