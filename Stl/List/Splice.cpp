/**
 * \file  Splice.cpp
 * \brief
 *
 * \todo
 */


#include <string>
#include <iostream>
#include <list>
#include <assert.h>

//-------------------------------------------------------------------------------------------------
#define STD_TRACE_VAR(v) \
    #v ": " << (v)
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::list<int> a {1, 2, 3, 4, 5, 6, 7, 8};
	std::list<int> b {5, 6, 7, 8};

	a.splice(a.end(), b);

	std::cout << "a contains:";
	for (auto &it : a )
		std::cout << ' ' << it;
	std::cout << '\n';

	std::cout << "b contains:";
	for (auto &it : b)
		std::cout << ' ' << it;
	std::cout << '\n';

	return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

a contains: 1 2 3 4 5 6 7 8 5 6 7 8
b contains:

#endif
