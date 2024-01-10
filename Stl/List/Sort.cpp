/**
 * \file  Sort.cpp
 * \brief Sort using std::list::sort() method
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::list<int> items {10, 30, 0};

	auto comp = [](const int a_it1, const int a_it2) -> bool
	{
		return a_it1 < a_it2;
	};

	items.sort(comp);

	std::cout << items << std::endl;

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

{10,30,0} -> {0,10,30}

#endif
