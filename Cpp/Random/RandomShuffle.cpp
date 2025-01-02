/**
 * \file  RandomShuffle.cpp
 * \brief
 *
 * Returns a random number which is is chosen by shuffling the elements of a vector which
 * only contains values that exist between the specified range
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
// Generates a random number between specified min/max boundaries using a vector to shuffle.
int
random2(int nMin, int nMax)
{
	std::vector<int> vi;
	static int nIndex = 0;

	for (int i = nMin; i < nMax; i ++) {
		vi.push_back(i);
    }

	std::random_shuffle(vi.begin(), vi.end());

	return vi[nIndex];
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	int i = 0;

	std::cout << std::endl;
	std::cout << "Using Random2 with std::vector shuffling" << std::endl << std::endl;

	for (i = 0; i < 10; i ++) {
		std::cout << random2(1, 100) << std::endl;
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Using Random2 with vector shuffling

97
19
65
67
67
47
19
90
1
91

#endif
