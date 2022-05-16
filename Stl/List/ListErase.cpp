/**
 * \file  ListErase.cpp
 * \brief Removes from the list container either a single element (position) or a range of elements ([first,last)).
 *
 * This effectively reduces the container size by the number of elements removed, which are destroyed.
 *
 * Unlike other standard sequence containers, list and forward_list objects are specifically
 * designed to be efficient inserting and removing elements in any position,
 * even in the middle of the sequence.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::list<int> items( {0, 1, 2, 3, 4, 5} );
	std::cout << TRACE_VAR(items) << std::endl;

	std::list<int>::iterator it_item = ++ (items.begin());

	// Erase #1
	it_item = items.erase(it_item);
	std::cout << "Erase #1: " << TRACE_VAR(items) << std::endl;

	// Erase #2
	++ it_item;

	items.erase(it_item, items.end());
	std::cout << "Erase #2: " << TRACE_VAR(items) << std::endl;

	return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

          items: std::list (size=6): {0,1,2,3,4,5}
Erase #1: items: std::list (size=5): {0,2,3,4,5}
Erase #2: items: std::list (size=2): {0,2}

#endif
