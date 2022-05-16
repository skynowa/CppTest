/**
 * \file  ListRemoveIf.cpp
 * \brief Removes from the container all the elements for which Predicate pred returns true
 *
 * This calls the destructor of these objects and reduces the container size by
 * the number of elements removed.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::list<int> listOfInts( {2, 3, 4, 6, 4, 9, 1, 2, 8, 9, 4, 6, 2} );

	std::cout << "Before: " << TRACE_VAR(listOfInts.size()) << std::endl;

	// Remove only first occurrence of element with value 4
	auto pred = [](const int &val) -> bool
	{
		return (val >= 2 && val < 5);
	};

	listOfInts.remove_if(pred);

	std::cout << "After: " << TRACE_VAR(listOfInts.size()) << std::endl;
	std::cout << listOfInts << std::endl;
	std::cout << std::endl;

	return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Before: listOfInts.size(): 13
After:  listOfInts.size(): 6

std::list (size=6): {6,9,1,8,9,6}

#endif
