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
	std::list<int> listOfInts( { 2, 3, 4, 6, 4, 9, 1, 2, 8, 9, 4, 6, 2, 4, 9 } );

	std::cout << TRACE_VAR(listOfInts) << std::endl;

	// Iterator itList points to element next to begin
	std::list<int>::iterator itList = ++(listOfInts.begin());

	// Erasing element represented by iterator itList i.e. 3
	itList = listOfInts.erase(itList);

	std::cout << TRACE_VAR(listOfInts) << std::endl;

	++ itList;

	// Erase a range of elements i.e. 6 to end
	listOfInts.erase(itList, listOfInts.end());

	std::cout << TRACE_VAR(listOfInts) << std::endl;

	return 0;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

listOfInts: std::list (size=15): {2,3,4,6,4,9,1,2,8,9,4,6,2,4,9}
listOfInts: std::list (size=14): {2,4,6,4,9,1,2,8,9,4,6,2,4,9}
listOfInts: std::list (size=2):  {2,4}

#endif
