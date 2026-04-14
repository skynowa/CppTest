/**
 * \file  Splice.cpp
 * \brief Transfer elements from one list to another
 *
 * This function just reassigns the internal pointers of each node to the new position without
 * copying or moving the data.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::list<int> a {1, 2, 3};
	std::list<int> b {10, 11, 12};

	a.splice(a.end(), b);

	std::cout << STD_TRACE_VAR(a) << std::endl;
	std::cout << STD_TRACE_VAR(b) << std::endl;

	return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

a: std::list (size=6): {1,2,3,10,11,12}
b: std::list (size=0): {}

#endif
