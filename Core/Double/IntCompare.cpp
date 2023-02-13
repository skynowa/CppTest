/**
 * \file  IntCompare.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const int    i = 0;
	const double d = 0.1;

	if (i < d) {
		std::cout << i << " < " << d << std::endl;
	}

	if (i > d) {
		std::cout << i << " > " << d << std::endl;
	}

	if (i == d) {
		std::cout << i << " == " << d << std::endl;
	}

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

0 < 0.1

#endif
