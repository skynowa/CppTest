/**
 * \file  JoinDetach.cpp
 * \brief Join detachable threads
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class Worker
{
public:
    void operator() () const
    {
        std::stringstream msg;
        msg << "[Worker] Thread ID: " << std::this_thread::get_id() << std::endl;

        std::cout << msg.str();
    }
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::vector<std::thread> threads;

    for (int i = 0; i < 3; ++ i) {
        threads.push_back( std::thread( Worker() ) );
    }

    std::cout << "Wait for all the worker thread to finish...\n" << std::endl;

    // Call join() function on each of the std::thread object
    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

    std::cout << "\nExiting" << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

---------------------------------------------
Wait for all the worker thread to finish...

[Worker] Thread ID: 135508116112960
[Worker] Thread ID: 135508105627200
[Worker] Thread ID: 135508095141440

Exiting
---------------------------------------------

#endif
