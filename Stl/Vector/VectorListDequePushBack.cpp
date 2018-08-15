/**
 * \file  main.cpp
 * \brief
 */


#include "../../StdTest.h"
#include "../../Stl.h"
//-------------------------------------------------------------------------------------------------
const std::size_t loops {10000000};
const std::string str   {"qwerty"};
//-------------------------------------------------------------------------------------------------
template<class T>
void
containerPushBack(
	T &a_cont
)
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();

	for (size_t i = 0; i < loops; ++ i) {
		const std::string s = std::to_string(i) + str + std::to_string(i);
		a_cont.push_back(s);
	}

	end = std::chrono::system_clock::now();

	const int elapsedMSec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

	// report
	if      (std::is_same<T, std::vector<std::string>>::value) {
		std::cout << "std::vector";
	}
	else if (std::is_same<T, std::list<std::string>>::value) {
		std::cout << "std::list";
	}
	else if (std::is_same<T, std::deque<std::string>>::value) {
		std::cout << "std::deque";
	}
	else {
		assert(false && "Unknown type");
	}

	std::cout << ": " << STD_TRACE_VAR(elapsedMSec) << std::endl;
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// std::vector
	{
		std::vector<std::string> cont;
		// cont.reserve(::loops);

		::containerPushBack(cont);
	}

	// std::list
	{
		std::list<std::string> cont;
		::containerPushBack(cont);
	}

	// std::deque
	{
		std::deque<std::string> cont;
		::containerPushBack(cont);
	}

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

std::vector: elapsedMSec: 5069
std::list:   elapsedMSec: 5668
std::deque:  elapsedMSec: 5259

#endif
