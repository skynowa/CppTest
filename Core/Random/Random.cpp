/**
 * \file  Random.cpp
 * \brief
 *
 * Author: Kevin Harris
 *
 * While random1 is typical of random number generations,
 * the function random2() returns a random number which is
 * is chosen by shuffling the elements of a vector which
 * only contains values that exist between the specified range
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
// Name: random1()
// Desc: Generates a random number between specified min/max boundaries
int
random1(int nMin, int nMax)
{
	int nRange = nMax - nMin;
	int nNum   = rand() % nRange;

	return nNum + nMin;
}
//--------------------------------------------------------------------------------------------------
// Name: random1()
// Desc: Generates a random number between specified min/max boundaries using
//       a vector to shuffle.
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

	// Seed the random-number generator with the current time
	// so that the numbers will be different every time we run.
	srand((unsigned)time(NULL));

	std::cout << "Using Random1 whith typical modulus ranging" << std::endl << std::endl;

	for (i = 0; i < 10; i ++) {
		std::cout << random1(1, 100) << std::endl;
    }

	std::cout << std::endl;
	std::cout << "Using Random2 with std::vector shuffling" << std::endl << std::endl;

	for (i = 0; i < 10; i ++) {
		std::cout << random2(1, 100) << std::endl;
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT


84
6
21
56
5
8
20
42
62
63

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
