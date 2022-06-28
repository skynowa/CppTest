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
std::atomic_flag lock {ATOMIC_FLAG_INIT};
//-------------------------------------------------------------------------------------------------
void f(const int n)
{
    for (int cnt = 0; cnt < 3; ++ cnt) {
        while (lock.test_and_set(std::memory_order_acquire)) {
            ;
        }

        std::cout << "Thread Output - " << STD_TRACE_VAR(n) << std::endl;

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

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

Thread Output - n: 0
Thread Output - n: 0
Thread Output - n: 2
Thread Output - n: 1
Thread Output - n: 0
Thread Output - n: 1
Thread Output - n: 2
Thread Output - n: 1
Thread Output - n: 2
Thread Output - n: 3
Thread Output - n: 3
Thread Output - n: 3

#endif
