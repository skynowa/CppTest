/**
 * \file  Rand.cpp
 * \brief Random number generations
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
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

#endif
