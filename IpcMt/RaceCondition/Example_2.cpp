/**
 * \file  Example_2.cpp
 * \brief Here both the threads are racing for the common resource std::cout
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
void func()
{
    for (int i = 0; i > -10; -- i) {
        std::cout << "From std::thread: " << i << std::endl;
    }
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::thread t(func);

    for (int i = 0; i < 10; ++ i) {
        std::cout << "From main: " << i << std::endl;
    }

    t.join();

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

From std::thread: From main: 00
From main:
From std::thread: -1
From std::thread: -2
From std::thread: -3
From std::thread: -4
From std::thread: -5
From std::thread: -6
From std::thread: -7
From std::thread: -8
From std::thread: -9
1
From main: 2
From main: 3
From main: 4
From main: 5
From main: 6
From main: 7
From main: 8
From main: 9

#endif
