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


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
template<class ContainerT, class ValueT>
ContainerT &
removeErase(
	ContainerT   &out_vec,	///< [in,out]
    const ValueT &a_value	///<
)
{
	std::cout << TRACE_VAR(out_vec) << std::endl;

	// remove
	auto it = std::remove(out_vec.begin(), out_vec.end(), a_value);
	std::cout << TRACE_VAR(out_vec) << std::endl;

	// really remove all elements with value
	out_vec.erase(it, out_vec.end());
	std::cout << TRACE_VAR(out_vec) << std::endl;

	return out_vec;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::vector<int> vec {0, 10, 20, 99, 100};

	::removeErase(vec, 99);

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

out_vec: std::vector (size=5): {0,10,20,99,100}
out_vec: std::vector (size=5): {0,10,20,100,100}
out_vec: std::vector (size=4): {0,10,20,100}

#endif
