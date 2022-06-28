/**
 * \file  LockGuard.cpp
 * \brief
 *
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
std::mutex m1;
//--------------------------------------------------------------------------------------------------
void
shared_print(std::string msg, int id)
{
	std::lock_guard<std::mutex> guard(m1);

	std::cout << msg << " :: " << id << std::endl;
}
//--------------------------------------------------------------------------------------------------
void
function1()
{
    for (int i = 0; i > -10; i--)
        shared_print("From t1", i);
}
//--------------------------------------------------------------------------------------------------
int main()
{
    std::thread t1(function1);

    for (int i = 0; i < 10 ; i++)
        shared_print("From Main", i);

    t1.join();

    return 0;
}
//--------------------------------------------------------------------------------------------------
