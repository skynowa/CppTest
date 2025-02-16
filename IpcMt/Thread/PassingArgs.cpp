/**
 * \file  PassingArgs.cpp
 * \brief Pass function ptr with args
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
void
worker(
    const int          x,
    const std::string &str
)
{
    std::cout << "[worker] Passed Number = " << x   << std::endl;
    std::cout << "[worker] Passed String = " << str << std::endl;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    const int         x   = 10;
    const std::string str = "Sample String";

    std::thread t(worker, x, str);
    t.join();

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

---------------------------------------------
[worker] Passed Number = 10
[worker] Passed String = Sample String
---------------------------------------------

#endif
