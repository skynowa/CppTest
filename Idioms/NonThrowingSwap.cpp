/**
 * \file  NonThrowingSwap.cpp
 * \brief To implement an exception safe and efficient swap operation
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
template<class T>
void
swap(T &a, T &b)
{
	T temp(a);
	a = b;
	b = temp;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	int a {10};
	int b {20};

    std::cout << TRACE_VAR2(a, b) << std::endl;

	::swap(a, b);

    std::cout << TRACE_VAR2(a, b) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

a: 10, b: 20
a: 20, b: 10

#endif
