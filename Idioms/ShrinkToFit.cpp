/**
 * \file  ShrinkToFit.cpp
 * \brief Minimize the capacity of a container just enough to hold existing range.
 *
 * In C++11 some containers declare such idiom as function shrink_to_fit(),
 * e.g. vector, deque, basic_string. shrink_to_fit() is a non-binding request
 * to reduce capacity() to size()
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	{
		std::vector<int> v;
		v.reserve(64);
		std::cout << TRACE_VAR2(v.size(), v.capacity()) << " -> ";

		// v is swapped with its temporary copy, which is capacity optimal
		std::vector<int>(v).swap(v);
		std::cout << TRACE_VAR2(v.size(), v.capacity()) << std::endl;
	}

	{
		std::vector<int> v;
		v.reserve(64);
		std::cout << TRACE_VAR2(v.size(), v.capacity()) << " -> ";

		// v is swapped with its temporary copy, which is capacity optimal
		std::vector<int>(v.begin(), v.end()).swap(v);
		std::cout << TRACE_VAR2(v.size(), v.capacity()) << std::endl;
	}

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

v.size(): 0, v.capacity(): 64 -> v.size(): 0, v.capacity(): 0
v.size(): 0, v.capacity(): 64 -> v.size(): 0, v.capacity(): 0

#endif
