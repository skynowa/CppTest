/**
 * \file  ReverseString.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
template<typename T >
void
reverseString(T &a)
{
	const std::size_t _size = a.size();

	for (typename T::size_type i = 0; i < (_size / 2); ++ i) {
		const std::size_t index1 = i;
		const std::size_t index2 = (_size - 1) - i;

		std::swap(a[index1], a[index2]);
	}
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::string str = "54321";
    ::reverseString(str);

    std::cout << TRACE_VAR(str) << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

str: gfedcba

#endif
