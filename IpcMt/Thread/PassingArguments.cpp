/**
 * \file  PassingArguments.cpp
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
    const int         x,
    const std::string str
)
{
    std::cout << "Passed Number = " << x   << std::endl;
    std::cout << "Passed String = " << str << std::endl;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    const int         x   = 10;
    const std::string str = "Sample String";

    std::thread threadObj(worker, x, str);

    threadObj.join();

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Passed Number = 10
Passed String = Sample String

#endif
