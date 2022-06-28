/**
 * \file  Flag.cpp
 * \brief
 *
 * \review
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
std::atomic_flag flag {ATOMIC_FLAG_INIT};
//-------------------------------------------------------------------------------------------------
void
worker(const int a_value)
{
    for (int i = 0; i < 3; ++ i) {
        while ( ::flag.test_and_set(std::memory_order_acquire) ) {
            ;
        }

        std::cout << "[Worker] " << STD_TRACE_VAR(a_value) << std::endl;

        ::flag.clear(std::memory_order_release);
    }
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::vector<std::thread> threads;

    for (int i = 0; i < 4; ++ i) {
        threads.emplace_back(worker, i);
    }

    for (auto &it_thread : threads) {
        it_thread.join();
    }

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

[Worker] - i: 0
[Worker] - i: 0
[Worker] - i: 2
[Worker] - i: 1
[Worker] - i: 0
[Worker] - i: 1
[Worker] - i: 2
[Worker] - i: 1
[Worker] - i: 2
[Worker] - i: 3
[Worker] - i: 3
[Worker] - i: 3

#endif
