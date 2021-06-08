/**
 * \file  AverageOfAnArray.cpp
 * \brief
 *
 * \review
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
template <typename T>
T
average(const T *array, const int length)
{
	T sum {};

	for (int i = 0; i < length; i++) {
		sum += array[i];
	}

	sum /= length;

	return sum;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const int array1[] { 5, 3, 2, 1, 4 };
	std::cout << "Average of array1 = " << ::average(array1, 5) << std::endl;

	const double array2[] { 3.12, 3.45, 9.23, 6.34 };
    std::cout << "Average of array2 = " << ::average(array2, 4) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

Average of array1 = 3
Average of array2 = 5.535

#endif
