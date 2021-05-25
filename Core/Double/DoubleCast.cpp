/**
 * \file  DoubleCast.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	{
	    double     d = -10.15;
	    signed int i = static_cast<signed int>(d);

	    std::cout << TRACE_VAR2(d, i) << std::endl;
    }

    {
	    double     d = 20.25;
	    signed int i = static_cast<signed int>(d);

	    std::cout << TRACE_VAR2(d, i) << std::endl;
	}

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

d: -10.15, i: -10
d: 20.25,  i: 20


#endif
