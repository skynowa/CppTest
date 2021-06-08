/**
 * \file  MultimapBasics.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::multimap<char, int> mmapOfPos
	{
		{'t', 0},
		{'h', 1},
		{'i', 2},
		{'s', 3},
		{'i', 5},
		{'s', 6},
		{'i', 8}
	};

	mmapOfPos.insert( std::pair<char, int>('t', 9) );

	// Iterating over the multimap using iterator
	for (auto it = mmapOfPos.begin(); it != mmapOfPos.end(); it++) {
		std::cout << it->first << " :: " << it->second << std::endl;
	}

	std::cout << std::endl << std::endl;

	// Iterating over multimap using range based loop
	for (auto &elem : mmapOfPos) {
		std::cout << elem.first << " :: " << elem.second << std::endl;
	}

	return 0;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT

h :: 1
i :: 2
i :: 5
i :: 8
s :: 3
s :: 6
t :: 0
t :: 9


h :: 1
i :: 2
i :: 5
i :: 8
s :: 3
s :: 6
t :: 0
t :: 9

#endif
