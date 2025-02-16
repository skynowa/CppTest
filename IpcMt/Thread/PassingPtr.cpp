/**
 * \file  PassingPtr.cpp
 * \brief
 *
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
void worker(int *out_p)
{
    std::cout << "worker [begin]: out_p = " << *out_p << std::endl;

    std::chrono::milliseconds dura(1000);
    std::this_thread::sleep_for( dura );

    *out_p = 19;

    std::cout << "worker [end]: out_p = " << *out_p << std::endl;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    int i = 10;

    std::cout << "Inside Main Thread: i = " << i << std::endl;

    std::thread t(::worker, &i);
    t.detach();

    std::cout << "Inside Main Thread: i = " << i << std::endl;

    std::chrono::milliseconds dura( 2000 );
    std::this_thread::sleep_for( dura );

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Inside Main Thread: i = 10
Inside Main Thread: i = 10

worker [begin]: out_p = 10
worker [end]:   out_p = 19

#endif
