/**
 * \file  SetNewHandler.cpp
 * \brief Set new handler function
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
void onOutOfMemory()
{
    std::cout << "Memory allocation failed, terminating" << std::endl;

    std::abort();
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::set_new_handler(onOutOfMemory);

    try {
        while (true) {
            std::cout << "call new..." << std::endl;

            new int[1000'000'000ul]();
        }
    }
    catch (const std::bad_alloc &e) {
        std::cout << STD_TRACE_VAR(e.what()) << std::endl;
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

---------------------------------------------
Killed
---------------------------------------------

#endif
