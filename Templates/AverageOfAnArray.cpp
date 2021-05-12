/**
 * \file  AverageOfAnArray.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

using namespace std;
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
int main()
{
	const int array1[] { 5, 3, 2, 1, 4 };
	cout << "Average of array1 = " << ::average(array1, 5) << endl;

	const double array2[] { 3.12, 3.45, 9.23, 6.34 };
    cout << "Average of array2 = " << ::average(array2, 4) << endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

Average of array1 = 3
Average of array2 = 5.535

#endif
