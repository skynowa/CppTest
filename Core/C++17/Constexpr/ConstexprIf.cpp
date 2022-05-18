/**
 * \file  ConstexprIf.cpp
 * \brief constexpr if
 *
 * Write code that is instantiated depending on a compile-time condition.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
template <typename T>
constexpr bool
isIntegral()
{
	// !!! std::cout - NOT compiled !!!

	if constexpr (std::is_integral<T>::value) {
		// std::cout << STD_TRACE_VAR("constexpr - true") << std::endl;
		return true;
	} else {
		// std::cout << STD_TRACE_VAR("constexpr - false") << std::endl;
		return false;
	}
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	static_assert(isIntegral<int>() == true);
	static_assert(isIntegral<char>() == true);
	static_assert(isIntegral<double>() == false);

	struct S {};
	static_assert(isIntegral<S>() == false);

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
