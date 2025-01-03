/**
 * \file  CreationByFunctionObjects.cpp
 * \brief
 *
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class Worker
{
public:
    void operator() ()
    {
        for (int i = 0; i < 10; ++ i) {
            std::cout << "Worker Executing - " << i << std::endl;
        }
    }
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::thread threadObj( (Worker()) );

    for (int i = 0; i < 10; ++ i) {
        std::cout << "Display From Main Thread - " << i <<std::endl;
    }

    std::cout << "Waiting For Thread to complete" << std::endl;

    threadObj.join();

    std::cout << "Exiting from Main Thread" <<std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Display From Main Thread - Worker Executing - 00
Display From Main Thread - 1

Worker Executing - 1
Worker Executing - 2
Worker Executing - 3
Worker Executing - 4
Worker Executing - 5
Worker Executing - 6
Worker Executing - 7
Worker Executing - 8
Worker Executing - 9
Display From Main Thread - 2
Display From Main Thread - 3
Display From Main Thread - 4
Display From Main Thread - 5
Display From Main Thread - 6
Display From Main Thread - 7
Display From Main Thread - 8
Display From Main Thread - 9
Waiting For Thread to complete
Exiting from Main Thread


#endif
