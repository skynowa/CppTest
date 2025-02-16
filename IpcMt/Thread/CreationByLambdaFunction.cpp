/**
 * \file  CreationByLambdaFunction.cpp
 * \brief
 *
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
const int threadsNum {3};
//--------------------------------------------------------------------------------------------------
auto worker = []() -> void
{
	for (int i = 0; i < ::threadsNum; ++ i) {
		std::cout << "Worker Executing - " << i << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::thread t(worker);

    for (int i = 0; i < ::threadsNum; ++ i) {
        std::cout << "Display From Main Thread - " << i <<std::endl;
    }

    t.join();

    std::cout << "Exiting from Main Thread" << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

---------------------------------------------
Display From Main Thread - 0
Display From Main Thread - 1
Display From Main Thread - 2
Worker Executing - 0
Worker Executing - 1
Worker Executing - 2
Exiting from Main Thread
---------------------------------------------

#endif
