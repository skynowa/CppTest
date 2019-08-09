/**
 * \file  main.cpp
 * \brief constexpr if

 Write code that is instantiated depending on a compile-time condition.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	template <typename T>
	constexpr bool isIntegral() {
	if constexpr (std::is_integral<T>::value) {
		return true;
	} else {
		return false;
	}
	}
	static_assert(isIntegral<int>() == true);
	static_assert(isIntegral<char>() == true);
	static_assert(isIntegral<double>() == false);
	struct S {};
	static_assert(isIntegral<S>() == false);

    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
