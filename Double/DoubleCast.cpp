/**
 * \file  main.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	{
	    double     d = -0.15;
	    signed int i = static_cast<signed int>(d);

	    std::cout << TRACE_VAR2(d, i) << std::endl;
    }

    {
	    double     d = 0.25;
	    signed int i = static_cast<signed int>(d);

	    std::cout << TRACE_VAR2(d, i) << std::endl;
	}

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

d: -0.15, i: 0
d:  0.25, i: 0

#endif

