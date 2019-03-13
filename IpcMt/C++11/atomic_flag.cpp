/**
 * \file  main.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic>

//-------------------------------------------------------------------------------------------------
std::atomic_flag lock = ATOMIC_FLAG_INIT;
//-------------------------------------------------------------------------------------------------
void f(const int n)
{
    for (int cnt = 0; cnt < 3; ++cnt) {
        while (lock.test_and_set(std::memory_order_acquire)) {
             ;
        }

        std::cout << "Output from thread " << TRACE_VAR(n) << std::endl;
        std::cout << "----------" << std::endl;

        lock.clear(std::memory_order_release);
    }
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::vector<std::thread> v;

    for (int n = 0; n < 4; ++ n) {
        v.emplace_back(f, n);
    }

    for (auto& t : v) {
        t.join();
    }

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif

