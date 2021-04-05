/**
 * \file
 * \brief
 *
 * \todo
 */


#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::list<std::size_t> mylist;
	mylist.push_back(10);
	mylist.push_back(30);
	mylist.push_back(0);

	mylist.sort(
		[](const std::size_t a_it1, const std::size_t a_it2) -> bool
		{
			return a_it1 < a_it2;
		});

	for (auto &it : mylist) {
		std::cout << ',' << it;
	}

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

10,30,0 -> 0,10,30

#endif
