/**
 * \file  PassingReferencesToThread.cpp
 * \brief
 *
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
void
worker(
    const int &x
)
{
    int &y = const_cast<int &>(x);

    ++ y;

    std::cout << "worker x = " << x << std::endl;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    int x = 9;

    std::cout << "In Main Thread : Before Thread Start x = " << x << std::endl;

    std::thread threadObj(::worker, std::ref(x));

    threadObj.join();

    std::cout << "In Main Thread : After Thread Joins x = " << x << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

In Main Thread : Before Thread Start x = 9
worker x = 10
In Main Thread : After Thread Joins x = 10

#endif
