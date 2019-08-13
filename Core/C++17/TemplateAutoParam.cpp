/**
 * \file  main.cpp
 * \brief Declaring non-type template parameters with auto
 *
 * Following the deduction rules of auto, while respecting the non-type template parameter
 * list of allowable types[*], template arguments can be deduced from the types of its arguments:
 *
 * * - For example, you cannot use a double as a template parameter type, which also makes
 *     this an invalid deduction using auto.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
template <auto... seq>
struct IntegerSequence
{
	// Implementation here ...

	static constexpr std::size_t size()
	{
		return 3;
	}
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// Explicitly pass type `int` as template argument.
	{
		auto seq = std::integer_sequence<int, 0, 1, 2>();
    	std::cout << TRACE_VAR(seq.size()) << std::endl;
	}

	// Type is deduced to be `int`.
	{
		auto seq = IntegerSequence<0, 1, 2, 7>();
    	std::cout << TRACE_VAR(seq.size()) << std::endl;
	}

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

seq.size(): 3
seq.size(): 3

#endif
