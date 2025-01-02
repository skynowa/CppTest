/**
 * \file  GccLeaky.cpp
 * \brief https://www.youtube.com/watch?v=S9_mYmvO4Ow
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	auto l = [val = 2]()
	{
		std::cout << __FUNCTION__ << std::endl;

		return val;
	};

	std::cout << STD_TRACE_VAR(l.__val) << std::endl;

	l.__val = 4;

	std::cout << STD_TRACE_VAR(l.__val) << std::endl;

    return l();
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

l.__val: 2
l.__val: 4
operator()

#endif
