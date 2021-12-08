/**
 * \file  ListConditionalErase.cpp
 * \brief List Conditional Erase While Iteration
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main()
{
	// Create a list and initialize it with 10 elements
	std::list<int> listOfInts { 2, 3, 3, 4, 8, 9, 4, 6, 8, 3 };

	// Iterate over the list using Iterators and erase elements
	// which are multiple of 3 while iterating through list
	for (auto it = listOfInts.begin(); it != listOfInts.cend(); ) {
		// Remove elements while iterating
		if ((*it) % 3 == 0) {
			// erase() makes the passed iterator invalid
			// But returns the iterator to the next of deleted element
			it = listOfInts.erase(it);
		} else {
			++ it;
		}
	}

	// Iterate over the list using for_each & Lambda Function and display contents
	std::for_each(listOfInts.cbegin(), listOfInts.cend(),
		[](const int val) -> void
		{
			std::cout << val << ",";
		});

	std::cout << std::endl;

	return 0;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT

2,4,8,4,8,

#endif
