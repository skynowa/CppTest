/**
 * \file  DiamondInheritance.cpp
 * \brief Virtual inheritance
 *
 * \see   https://www.youtube.com/watch?v=7g8HufwNa0g&t=974s
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
struct A
{
	const int value {7};

    A()
    {
        STD_TRACE_FUNC;
    }
};
//--------------------------------------------------------------------------------------------------
struct B :
	virtual A
{
    B()
    {
        STD_TRACE_FUNC;
    }
};
//--------------------------------------------------------------------------------------------------
struct C :
	virtual A
{
    C()
    {
        STD_TRACE_FUNC;
    }
};
//--------------------------------------------------------------------------------------------------
struct D :
    B, C
{
    D()
    {
        STD_TRACE_FUNC;
    }
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	D d;

	std::cout << "\n\t" << STD_TRACE_VAR(d.value) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

// Without virtual

	::: A :::
	::: B :::

	::: A :::
	::: C :::

	::: D :::

    // d.value - error: request for member ‘value’ is ambiguous

// With virtual

	::: A :::
	::: B :::
	::: C :::
	::: D :::

    d.value: 7

#endif
