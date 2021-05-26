/**
 * \file  RegualarFuncFunctor.cpp
 * \brief Regualar function as functor
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
double
Pow(double x, double y)
{
	return pow(x, y);
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::set<int>   myset {3, 1, 5, 4, 2};
	std::deque<int> d;

	auto f = std::function<double (double, double)>(Pow);

	std::transform(myset.begin(), myset.end(),
				std::back_inserter(d),
				std::bind(f, std::placeholders::_1, 2));

	for (int x : d) {
		std::cout << x << " ";
	}

	std::cout << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

1 4 9 16 25

#endif
