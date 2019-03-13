/**
 * \file  set_insert.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <set>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::set<int> s;

	auto it1 = s.insert(1);
	std::cout << TRACE_VAR(it1.second) << std::endl;

	auto it2 = s.insert(2);
	std::cout << TRACE_VAR(it2.second) << std::endl;

	auto it3 = s.insert(2);
	std::cout << TRACE_VAR(it3.second) << std::endl;

	auto it4 = s.insert(3);
	std::cout << TRACE_VAR(it4.second) << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

it1.second: 1
it2.second: 1
it3.second: 0
it4.second: 1

#endif

