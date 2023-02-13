/**
 * \file  EraseRemove.cpp
 * \brief
 *
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::vector<int> vec {10,20,30,30,20,10,10,20};			// 10 20 30 30 20 10 10 20

	// remove
	auto itEnd = std::remove(vec.begin(), vec.end(), 20);	// 10 30 30 10 10 ?  ?  ?

	std::cout << "[remove it]:";
	for (auto it = vec.begin(); it != itEnd; ++ it) {
		std::cout << ' ' << *it;
	}
	std::cout << '\n';

	std::cout << "[remove]:   ";
	for (auto &it : vec) {
		std::cout << ' ' << it;
	}
	std::cout << '\n';

	// erase
	vec.erase(itEnd, vec.end());
	std::cout << "[erase]:    ";
	for (auto &it : vec) {
		std::cout << ' ' << it;
	}
	std::cout << '\n';

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

[remove it]: 10 30 30 10 10
[remove]:    10 30 30 10 10 10 10 20
[erase]:     10 30 30 10 10

#endif
