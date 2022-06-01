/**
 * \file  JoinDetachThread.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class WorkerThread
{
public:
    void operator() () const
    {
        std::stringstream msg;
        msg << "Thread ID: " << std::this_thread::get_id() << std::endl;

        std::cout << msg.str();
    }
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::vector<std::thread> threads;

    for (int i = 0; i < 3; ++ i) {
        threads.push_back( std::thread( WorkerThread() ) );
    }

    std::cout << "Wait for all the worker thread to finish...\n" << std::endl;

    // Call join() function on each of the std::thread object
    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

    std::cout << "\nExiting from Main Thread" << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Wait for all the worker thread to finish...

Thread ID: 140114755426048
Thread ID: 140114772211456
Thread ID: 140114763818752

Exiting from Main Thread

#endif
