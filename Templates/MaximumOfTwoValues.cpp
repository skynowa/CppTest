/**
 * \file  MaximumOfTwoValues.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

using namespace std;
//--------------------------------------------------------------------------------------------------
template <typename T>
const T &
maximum(const T &a, const T&b)
{
	return (a > b) ? a : b;
}
//--------------------------------------------------------------------------------------------------
int main()
{
	{
		int i = 78;
		int j = 89;

		cout << "maximum(i, j) = " << maximum(i, j) << endl;
	}

	{
		double a = 7.89;
		double b = 3.56;

		cout << "maximum(a, b) = " << maximum(a, b) << endl;
	}

	{
		string s1 = "Hello";
		string s2 = "World";

		cout << "maximum(s1, s2) = " << maximum(s1, s2) << endl;
	}

	return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

maximum(i, j) = 89
maximum(a, b) = 7.89
maximum(s1, s2) = World

#endif
