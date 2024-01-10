/**
 * \file  SortWithAlgo.cpp
 * \brief Sort using std::sort() algo
 *
 * Can't use std::sort to sort std::list, because std::sort requires iterators to be random access,
 * and std::list iterators are only bidirectional.
 *
 * However, std::list has a member function sort that will sort it:
 *
 * \code{.cpp}
 * std::list::sort();
 * std::list::sort(comparator);
 * \endcode
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::list<int> items {10, 30, 0};

	// Compiler error
#if 0
	std::sort(items.begin(), items.end());
#endif

	std::cout << items << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

{10,30,0}

#endif
