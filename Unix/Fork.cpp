/**
 * \file  Fork.cpp
 * \brief Fork process
 *
 * \review
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    pid_t pidRv {};

    pidRv = ::fork();
    pidRv = ::fork();
    pidRv = ::fork();
    pidRv = ::fork();

    if (pidRv > 0) {
        std::cout << "Linux: " << TRACE_VAR(pidRv) << std::endl;
    } else {
        std::cout << "GNU: "   << TRACE_VAR(pidRv) << std::endl;
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

// creates 1 parent and 1 child processes per fork()

Linux: pidRv: 24735
GNU: pidRv: 0
Linux: pidRv: 24739
Linux: pidRv: 24740
Linux: pidRv: 24742
GNU: pidRv: 0
Linux: pidRv: 24743
Linux: pidRv: 24744
GNU: pidRv: 0
GNU: pidRv: 0
GNU: pidRv: 0
Linux: pidRv: 24745
GNU: pidRv: 0
Linux: pidRv: 24746
GNU: pidRv: 0
GNU: pidRv: 0


#endif
