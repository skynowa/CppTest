/**
 * \file  CtorByFuncObject.cpp
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
    std::thread t{ Worker() };

    for (int i = 0; i < ::threadsNum; ++ i) {
    	std::cout << "[Main] - " << i <<std::endl;
    }

    t.join();

    std::cout << "[Main] - Exiting" <<std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

---------------------------------------------
[Main] - 0
[Main] - 1
[Main] - 2
[Worker] 0
[Worker] 1
[Worker] 2
[Main] - Exiting
---------------------------------------------

#endif
