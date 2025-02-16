/**
 * \file  CtorByMethodPtr.cpp
 * \brief Ctor - pass by method / static method pointer
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

    void foo() const
    {
        for (int i = 0; i < ::threadsNum; ++ i) {
        	std::cout << "[Worker] " << i << std::endl;
        }
    }

    static void staticFoo()
    {
        for (int i = 0; i < ::threadsNum; ++ i) {
        	std::cout << "[Worker] Static " << i << std::endl;
        }
    }
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    // by method pointer
    {
        Worker worker;

        std::thread t(&Worker::foo, &worker);

        for (int i = 0; i < ::threadsNum; ++ i) {
        	std::cout << "[Main] - " << i << std::endl;
        }

        t.join();

        std::cout << "[Main] - Exiting" << std::endl;
        std::cout << std::endl;
    }

    // by static method pointer
    {
        std::thread t(&Worker::staticFoo);

        for (int i = 0; i < ::threadsNum; ++ i) {
        	std::cout << "[Main] - " << i << std::endl;
        }

        t.join();

        std::cout << "[Main] - Exiting" << std::endl;
    }

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

[Main] - 0
[Main] - 1
[Main] - 2
[Worker] Static 0
[Worker] Static 1
[Worker] Static 2
[Main] - Exiting
---------------------------------------------

#endif
