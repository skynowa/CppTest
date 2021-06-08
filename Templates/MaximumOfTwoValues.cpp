/**
 * \file  MaximumOfTwoValues.cpp
 * \brief
 *
 * \review
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
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

		std::cout << "maximum(i, j) = " << maximum(i, j) << std::endl;
	}

	{
		double a = 7.89;
		double b = 3.56;

		std::cout << "maximum(a, b) = " << maximum(a, b) << std::endl;
	}

	{
		std::string s1 = "Hello";
		std::string s2 = "World";

		std::cout << "maximum(s1, s2) = " << maximum(s1, s2) << std::endl;
	}

	return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

maximum(i, j) = 89
maximum(a, b) = 7.89
maximum(s1, s2) = World

#endif
