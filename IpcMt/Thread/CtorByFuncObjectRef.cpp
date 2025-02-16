/**
 * \file  CtorByFuncObjectRef.cpp
 * \brief Ctor - pass by std::ref
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
const int threadsNum {3};
//--------------------------------------------------------------------------------------------------
class Worker
{
public:
    Worker() = default;
   ~Worker() = default;

    void operator() () const
    {
        for (int i = 0; i < ::threadsNum; ++ i) {
            std::cout << "[Worker] " << i << std::endl;
        }
    }
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    Worker worker;

    std::thread t( std::ref(worker) );

    for (int i = 0; i < ::threadsNum; ++ i) {
        std::cout << "[Main] - " << i << std::endl;
    }

    t.join();

    std::cout << "[Main] - Exiting" << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

---------------------------------------------
[Main] - 0
[Main] - 1
[Main] - 2
[Main] - Waiting thread to complete
[Worker] 0
[Worker] 1
[Worker] 2
[Main] - Exiting
---------------------------------------------

#endif
