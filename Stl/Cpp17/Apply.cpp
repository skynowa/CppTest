/**
 * \file  main.cpp
 * \brief std::apply
 *
 * \todo
 *
 * Invoke a Callable object with a tuple of arguments.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	auto add = [](int x, int y)
	{
		return x + y;
	};

	std::apply(add, std::make_tuple(1, 2)); // == 3

    // std::cout << STD_TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
