#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	// Create a list and initialize it with 7 elements
	std::list<int> listOfInts( { 2, 3, 4, 6, 4, 9, 1, 2, 8, 9, 4, 6, 2 });

	// Remove only first occurrence of element with value 4

	listOfInts.remove_if([](const int & val) {
		if(val >= 2 && val < 5)
			return true;
		else
			return false;
	});

	std::cout << "size: " << listOfInts.size() << std::endl << std::endl;

	for (const auto &val : listOfInts) {
		std::cout << val << std::endl;
	}

	return 0;
}