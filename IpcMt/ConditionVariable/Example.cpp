/**
 * \file  Example.cpp
 * \brief
 *
 * \todo
 */

// cpp11_cond_variable_example.cpp
// g++ -std=c++11 condition_variable.cpp -o main -lpthread


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
bool                    isReady;
std::mutex              mutex;
std::condition_variable condvar;
std::queue<int>         messageQ;
//-------------------------------------------------------------------------------------------------
void Producer()
{
	std::cout << "::: Producer :::" << std::endl;

	for (auto x = 0; x < 10; ++ x) {
		std::lock_guard<std::mutex> guard(mutex);

		std::cout << "Producing message: " << x << " th" << std::endl;
		messageQ.push(x);
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	{
		std::lock_guard<std::mutex> guard(mutex);

		isReady = true;
	}

	std::cout << "::: Producer has completed :::" << std::endl;

	condvar.notify_one();
}
//-------------------------------------------------------------------------------------------------
void Consumer()
{
	{
		std::unique_lock<std::mutex> ulock(mutex);

		condvar.wait(ulock,
			[]{
				return isReady;
			});
	}

	std::cout << "\n\n::: Consumer is ready to get message :::" << std::endl;

	while ( !messageQ.empty() ) {
		std::lock_guard<std::mutex> guard(mutex);

		int i = messageQ.front();
		std::cout << "Consuming message: " << i << " th" << std::endl;
		messageQ.pop();
	}

	if ( !messageQ.empty() ) {
		std::cout << "There are still messages remained from producer" << std::endl;
	} else {
		std::cout << "All messages from producer has been processed" << std::endl;
	}
}
//-------------------------------------------------------------------------------------------------
int main()
{
	auto t1 = std::async(std::launch::async, Producer);
	auto t2 = std::async(std::launch::async, Consumer);

	t1.get();
	t2.get();

	return 0;
}
//-------------------------------------------------------------------------------------------------
