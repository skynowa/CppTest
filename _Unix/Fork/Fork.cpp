/**
 * \file  Fork.cpp
 * \brief process
 */


//---------------------------------------------------------------------------
#include <iostream>
#include <unistd.h>
//---------------------------------------------------------------------------
int main() {
    pid_t pidRv;

    pidRv = ::fork();
    pidRv = ::fork();
    pidRv = ::fork();
    pidRv = ::fork();

    if (pidRv) {
        std::cout << "Linux" << std::endl;
    } else {
        std::cout << "GNU"   << std::endl;
    }

    return 0;
}
//---------------------------------------------------------------------------

#if OUTPUT
// creates 1 parent and 1 child processes per fork()

$ ./Fork

    Linux
    Linux
    Linux
    Linux
    GNU
    GNU
    GNU
    Linux
    Linux
    GNU
    GNU
    GNU
    Linux
    Linux
    GNU
    GNU
#endif

