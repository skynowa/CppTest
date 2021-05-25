/**
 * \file  EraseRemove.cpp
 * \brief To eliminate elements from a STL container to reduce the size of it
 *
 * The std::remove algorithm does not eliminate elements from a container; it simply moves the
 * elements not being removed to the front of the container, leaving the contents at the end
 * of the container <b>undefined</b>.
 * This is because std::remove works only using a pair of forward iterators (Iterator Pair idiom),
 * and the generic concept of forward iterators does not know how to eliminate data elements
 * from an arbitrary data structure.
 * Only container member functions can eliminate container elements, as only members know
 * the details of the internal data structure.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::vector<int> vec {0, 10, 20, 99, 100};
	std::cout << TRACE_VAR(vec) << std::endl;

	// remove
	auto it = std::remove(vec.begin(), vec.end(), 99);
	std::cout << TRACE_VAR(vec) << std::endl;

	// really remove all elements with value 99
	vec.erase(it, vec.end());
	std::cout << TRACE_VAR(vec) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

vec: std::vector (size=5): {0,10,20,99,100}
vec: std::vector (size=5): {0,10,20,100,100}
vec: std::vector (size=4): {0,10,20,100}

#endif
